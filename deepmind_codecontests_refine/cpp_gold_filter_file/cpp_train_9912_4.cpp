#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("tune=native")
using namespace std;
using ll = long long;
using ld = long double;
template <class T>
using vec = vector<T>;
template <class T>
using v2d = vector<vector<T>>;
template <class T>
using prq = priority_queue<T>;
template <class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, s;
    scanf("%d%d", &n, &s);
    vec<int> x(n);
    ll r = 0;
    for (auto &i : x) scanf("%d", &i);
    int idx = -1;
    for (int i = 0; i < n; ++i) {
      r += x[i];
      if (r > s) {
        int mx = 0, mxi = -1;
        for (int j = 0; j <= i; ++j)
          if (x[j] > mx) {
            mx = x[j];
            mxi = j;
          }
        idx = mxi;
        break;
      }
    }
    printf("%d\n", idx + 1);
  }
}
