#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long long INF = 1e18;
string s;
const int N = 500000;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  vector<long long> b(n);
  vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    char cc;
    cin >> cc;
    a[i] = cc - '0';
    b[i] = a[i % k];
    c[i] = a[i % k];
  }
  long long nw = k - 1;
  while (nw && c[nw] == 9) {
    nw--;
  }
  c[nw]++;
  for (int i = nw + 1; i < k; i++) {
    c[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    c[i] = c[i % k];
  }
  long long ok = 1;
  for (int i = 0; i < n; i++) {
    if (a[i] < b[i]) {
      ok = 1;
      break;
    }
    if (a[i] > b[i]) {
      ok = 0;
      break;
    }
  }
  cout << n << "\n";
  if (ok) {
    for (int i = 0; i < n; i++) {
      cout << b[i];
    }
  } else {
    for (int i = 0; i < n; i++) {
      cout << c[i];
    }
  }
}
