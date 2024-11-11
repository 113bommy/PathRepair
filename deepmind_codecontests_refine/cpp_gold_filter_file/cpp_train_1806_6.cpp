#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
long long spow(long long a, long long b, long long M) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % M;
    }
    a = a * a % M;
    b /= 2;
  }
  return res;
}
long long inv(long long a, long long P) { return spow(a, P - 2, P); }
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  long long t;
  cin >> t;
  ;
  for (long long tt = (1); tt <= (t); ++tt) {
    long long k, l, r, p;
    cin >> k >> l >> r >> p;
    ;
    if (k == 1) {
      cout << 2 % p << "\n";
      continue;
    }
    if (p == 2) {
      cout << (k + 1) % 2 << "\n";
      continue;
    }
    if (k % p == 0) {
      if (k % 2 == 0) {
        cout << 1 << "\n";
      } else {
        cout << inv(spow(2, r - l, p), p) << "\n";
      }
      continue;
    }
    long long pow2l = spow(2, l, p - 1);
    long long denres = (spow(k, pow2l, p) + p - 1) % p;
    if (denres == 0) {
      if (0) cout << "a\n";
      if (k % 2 == 0) {
        cout << spow(2, r - l + 1, p) << "\n";
      } else {
        cout << 2 << "\n";
      }
    } else {
      if (0) cout << "b\n";
      long long pow2r = spow(2, r + 1, p - 1);
      long long numres = (spow(k, pow2r, p) + p - 1) % p;
      long long res = numres * inv(denres, p) % p;
      if (k % 2 == 1) {
        ;
        if (0) cout << "c\n";
        res = res * inv(spow(2, r - l, p), p) % p;
      }
      cout << res << "\n";
    }
  }
  return 0;
}
