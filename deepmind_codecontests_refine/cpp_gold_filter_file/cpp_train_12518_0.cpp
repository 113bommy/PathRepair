#include <bits/stdc++.h>
using namespace std;
inline void add(int &a, int b, int md) {
  a += b;
  if (a >= md) a -= md;
}
inline void sub(int &a, int b, int md) {
  a -= b;
  if (a < 0) a += md;
}
inline int mul(int a, int b, int md) { return (int)((long long)a * b % md); }
int pow(int a, int b, int md) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a, md);
    }
    a = mul(a, a, md);
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int p1 = 1e9 + 7;
  const int p2 = 1000000021;
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
      cin >> k[i];
    }
    sort(k.begin(), k.end());
    int s = 0, s2 = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s == 0 && s2 == 0) {
        add(s, pow(p, k[i], p1), p1);
        add(s2, pow(p, k[i], p2), p2);
      } else {
        sub(s, pow(p, k[i], p1), p1);
        sub(s2, pow(p, k[i], p2), p2);
      }
    }
    cout << s << endl;
  }
  return 0;
}
