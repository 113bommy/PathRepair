#include <bits/stdc++.h>
using namespace std;
struct cww {
  cww() {
    if (1) {
      ios::sync_with_stdio(false);
      cin.tie(0);
    }
  }
} star;
template <typename T>
inline bool chmin(T &l, T r) {
  bool a = l > r;
  if (a) l = r;
  return a;
}
template <typename T>
inline bool chmax(T &l, T r) {
  bool a = l < r;
  if (a) l = r;
  return a;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &it : v) is >> it;
  return is;
}
class range {
 private:
  struct I {
    int x;
    int operator*() { return x; }
    bool operator!=(I &lhs) { return x < lhs.x; }
    void operator++() { ++x; }
  };
  I i, n;

 public:
  range(int n) : i({0}), n({n}) {}
  range(int i, int n) : i({i}), n({n}) {}
  I &begin() { return i; }
  I &end() { return n; }
};
int N;
long long L;
int main() {
  while (cin >> N >> L) {
    vector<long long> c(100, 1e17);
    for (int i : range(N)) {
      cin >> c[i];
    }
    for (int i : range(1, 100)) {
      chmin(c[i], 2 * c[i - 1]);
    }
    long long ret = 0;
    int id = 0;
    while (L) {
      chmin(ret, c[id]);
      if (L & 1) ret += c[id];
      L >>= 1;
      id++;
    }
    for (int i : range(id, 50)) {
      chmin(ret, c[i]);
    }
    cout << ret << endl;
  }
  return 0;
}
