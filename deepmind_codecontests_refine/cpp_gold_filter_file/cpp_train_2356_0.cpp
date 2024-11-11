#include <bits/stdc++.h>
using namespace std;
const long long Q = 1e7;
const long long INF = 1e9;
const long long N = 1e5 + 3;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
long long n, m, x, y, z, c, e, f, cnt, lnt, qnt, wnt, k;
int s[N], d[N];
int a[7] = {1, 1, 0, 0, 0, 0, 0};
int b[7] = {0, 0, 0, 0, 0, 1, 1};
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i < n - 1; i++) {
    if (s[i] < s[i + 1] and s[i] < s[i - 1])
      cnt++;
    else if (s[i] > s[i + 1] and s[i] > s[i - 1])
      cnt++;
  }
  cout << cnt;
}
