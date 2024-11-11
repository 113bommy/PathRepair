#include <bits/stdc++.h>
using namespace std;
namespace mainns {
template <typename T>
int64_t sgn(T val) {
  return (T(0) < val) - (val < T(0));
}
namespace {
inline uint64_t gcdInternal(uint64_t a, uint64_t b) {
  if (b == 0) return a;
  return gcdInternal(b, a % b);
}
inline uint64_t gcdDecompositionInternal(uint64_t a, uint64_t b, int64_t& x,
                                         int64_t& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int64_t xx, yy;
  auto gcd = gcdDecompositionInternal(b, a % b, xx, yy);
  x = yy;
  y = xx - (a / b) * yy;
  return gcd;
}
}  // namespace
inline uint64_t greatestCommonDivisor(int64_t a, int64_t b) {
  a *= sgn(a);
  b *= sgn(b);
  if (a < b) std::swap(a, b);
  return gcdInternal(a, b);
}
inline uint64_t gcdDecomposition(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  auto aUnsigned = a * sgn(a);
  auto bUnsigned = b * sgn(b);
  auto gcd = (aUnsigned < bUnsigned)
                 ? gcdDecompositionInternal(aUnsigned, bUnsigned, x, y)
                 : gcdDecompositionInternal(bUnsigned, aUnsigned, y, x);
  x *= sgn(a);
  y *= sgn(b);
  return gcd;
}
template <int64_t MOD>
class Residue {
 public:
  Residue(int64_t from = 0) {
    int64_t remainder = from % MOD;
    if (remainder < 0) remainder += MOD;
    rep_ = remainder;
  }
  bool operator==(Residue<MOD> other) const { return rep_ == other.rep_; }
  Residue<MOD> operator++(int) { return *this = Residue(rep_ + 1); }
  Residue<MOD> operator++() { return *this = Residue(rep_ + 1); }
  Residue<MOD> operator--(int) { return *this = Residue(rep_ - 1); }
  Residue<MOD> operator--() { return *this = Residue(rep_ - 1); }
  Residue<MOD> operator+=(Residue<MOD> v) {
    return *this = Residue(rep_ + v.rep());
  }
  Residue<MOD> operator-=(Residue<MOD> v) {
    return *this = Residue(rep_ - v.rep());
  }
  Residue<MOD> operator*=(Residue<MOD> v) {
    return *this = Residue(rep_ * v.rep());
  }
  Residue<MOD> inversed() const {
    int64_t x, y;
    auto gcd = gcdDecomposition(rep_, MOD, x, y);
    assert(gcd == 1);
    return Residue(x);
  }
  int64_t rep() const { return rep_; }

 private:
  int64_t rep_;
};
template <int64_t MOD>
Residue<MOD> operator+(Residue<MOD> a, Residue<MOD> b) {
  return a += b;
}
template <int64_t MOD>
Residue<MOD> operator-(Residue<MOD> a, Residue<MOD> b) {
  return a -= b;
}
template <int64_t MOD>
Residue<MOD> operator*(Residue<MOD> a, Residue<MOD> b) {
  return a *= b;
}
template <int64_t MOD>
Residue<MOD> operator+(Residue<MOD> a, int64_t b) {
  return a += b;
}
template <int64_t MOD>
Residue<MOD> operator-(Residue<MOD> a, int64_t b) {
  return a -= b;
}
template <int64_t MOD>
Residue<MOD> operator*(Residue<MOD> a, int64_t b) {
  return a *= b;
}
template <int64_t MOD>
std::ostream& operator<<(std::ostream& outStream, Residue<MOD> a) {
  return outStream << a.rep();
}
class Solver613D {
 public:
  void run();
  string seq;
  vector<vector<int>> compareCash;
  int firstLesserDigit(int start1, int start2) {
    int len = start2 - start1;
    if (compareCash[start1][start2] != -2) return compareCash[start1][start2];
    if (start2 + len == seq.length()) {
      int res = -1;
      for (int offs = 0; offs < len; ++offs) {
        if (seq[start1 + offs] > seq[start2 + offs]) break;
        if (seq[start1 + offs] < seq[start2 + offs]) {
          res = start1 + offs;
          break;
        }
      }
      compareCash[start1][start2] = res;
      return res;
    }
    if (seq[start1] < seq[start2]) return 0;
    if (seq[start1] > seq[start2]) return -1;
    int ansForShifted = firstLesserDigit(start1 + 1, start2 + 1);
    if (ansForShifted == start1 + len) ansForShifted = -1;
    compareCash[start1][start2] = ansForShifted;
    return ansForShifted;
  }
};
using CodeforcesResidue = Residue<1000000007>;
void Solver613D::run() {
  int n;
  cin >> n;
  cin >> seq;
  compareCash =
      vector<vector<int>>(seq.length(), vector<int>(seq.length(), -2));
  vector<vector<CodeforcesResidue>> a(n, vector<CodeforcesResidue>(n + 1, 0));
  vector<vector<CodeforcesResidue>> s(n + 1,
                                      vector<CodeforcesResidue>(n + 1, 0));
  a[0][1] = 1;
  s[0][1] = 0;
  s[1][1] = 1;
  for (int j = 2; j <= n; ++j) {
    s[0][j] = 0;
    for (int i = 0; i < j; ++i) {
      if (i == 0) {
        a[i][j] = 1;
      } else {
        int p = i - (j - i);
        if (p >= 0) {
          int k = (seq[p] != '0' && firstLesserDigit(p, i) != -1) ? 1 : 0;
          a[i][j] += a[p][i] * k;
        }
        auto m = max(0, 2 * i + 1 - j);
        if (seq[i] != '0') a[i][j] += s[i][i] - s[m][i];
      }
      s[i + 1][j] = s[i][j] + a[i][j];
    }
  }
  CodeforcesResidue ans = 0;
  for (int i = 0; i < n; ++i) ans += a[i][n];
  cout << ans;
}
}  // namespace mainns
using CurrentSolver = mainns::Solver613D;
int main() {
  ios::sync_with_stdio(false);
  CurrentSolver().run();
  return 0;
}
