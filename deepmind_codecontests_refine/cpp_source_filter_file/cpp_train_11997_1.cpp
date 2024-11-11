#include <bits/stdc++.h>
using namespace std;
template <class T, class D>
class Range {
  class It {
   public:
    It(const T& v, const T& e, const D& s) : v_(v), e_(e), s_(s), end_(false) {
      checkEnd();
    };
    T operator*() { return v_; }
    It& operator++() {
      if (!end_) {
        v_ += s_;
        checkEnd();
      }
      return *this;
    }
    It operator++(int) {
      It r = *this;
      ++r;
      return r;
    }
    bool operator!=(const It& o) const {
      return (end_ && !o.end_) || (!end_ && o.end_) || (!end_ && (v_ != o.v_));
    }

   private:
    void checkEnd() {
      bool pos = (s_ > static_cast<D>(0));
      bool eq = v_ == e_;
      bool more = v_ > e_;
      end_ = eq || (more && pos) || (!more && !pos);
    }
    T v_;
    T e_;
    D s_;
    bool end_;
  };

 public:
  Range(const T& b, const T& e, const D& s) : b_(b), e_(e), s_(s){};
  It begin() const { return It{b_, e_, s_}; }
  It end() const { return It{e_, e_, s_}; }

 private:
  T b_;
  T e_;
  D s_;
};
template <typename T>
Range<T, T> R(const T& e) {
  typedef decltype(e - e) D;
  return Range<T, T>{static_cast<T>(0), e, static_cast<D>(1)};
}
template <typename T>
Range<T, T> R(const T& b, const T& e) {
  typedef decltype(e - b) D;
  return Range<T, T>{b, e, static_cast<D>(1)};
}
template <typename T, typename D>
Range<T, D> R(const T& b, const T& e, const D& d) {
  return Range<T, D>{b, e, d};
}
template <class T>
T read() {
  T r;
  cin >> r;
  return r;
}
struct Dir {
  int i;
  int j;
};
Dir D[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Dir CM[4][2] = {
    {{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}}, {{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}};
struct State {
  int d;
  int c;
  int b;
};
struct Block {
  Block(int i, int j, int h, int w, int c) : i(i), j(j), h(h), w(w), c(c) {}
  int i;
  int j;
  int h;
  int w;
  int c;
  State ns[4][2];
};
int main() {
  vector<string> field;
  int H = read<int>();
  int N = read<int>();
  for (size_t i = 0; i < H; ++i) {
    field.push_back(read<string>());
  }
  int W = field[0].size();
  auto in_field = [&](int i, int j) {
    return (i >= 0) && (i < H) && (j >= 0) && (j < W);
  };
  auto C = [&](int i, int j) { return in_field(i, j) ? field[i][j] - '0' : 0; };
  vector<vector<int>> F(H, vector<int>(W, -1));
  vector<Block> B;
  for (int i : R(H)) {
    for (int j : R(W)) {
      int c = C(i, j);
      if (c && F[i][j] == -1) {
        int h = 0;
        for (int k : R(i, H)) {
          if (C(k, j) != c) break;
          ++h;
        }
        int w = 0;
        for (int k : R(j, W)) {
          if (C(i, k) != c) break;
          ++w;
        }
        int b = B.size();
        B.emplace_back(i, j, h, w, c);
        for (int u : R(i, i + h)) {
          for (int v : R(j, j + w)) {
            F[u][v] = b;
          }
        }
      }
    }
  }
  for (size_t b : R(B.size())) {
    auto& block = B[b];
    for (int d : R(4)) {
      for (int c : R(2)) {
        Dir np{block.i + (block.h - 1) * ((D[d].i > 0) + (CM[d][c].i > 0)),
               block.j + (block.w - 1) * ((D[d].i > 0) + (CM[d][c].i > 0))};
        np.i += D[d].i;
        np.j += D[d].j;
        if (C(np.i, np.j)) {
          block.ns[d][c] = State{d, c, F[np.i][np.j]};
        } else {
          int nc, dc;
          if (c == 0) {
            nc = 1;
            dc = d;
          } else {
            nc = 0;
            dc = (d + 1) % 4;
          }
          block.ns[d][c] = State{dc, nc, int(b)};
        }
      }
    }
  }
  State s{1, 0, F[0][0]};
  for (int i : R(N)) {
    s = B[s.b].ns[s.d][s.c];
  }
  std::cout << B[s.b].c << endl;
  return 0;
}
