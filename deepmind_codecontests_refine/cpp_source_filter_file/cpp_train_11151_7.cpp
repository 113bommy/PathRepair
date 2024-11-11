#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 10e5 + 5;
long long arr[maxn];
const int MOD = 998244353;
int an[maxn], am[maxn];
int c[maxn];
string a, b;
int main() {
  arr[0] = 1;
  for (int i = 1; i < 200000; ++i) {
    arr[i] = arr[i - 1] * 2 % MOD;
  }
  int n, m;
  cin >> n >> m;
  cin >> a >> b;
  int cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    an[i] = a[n - i - 1] - '0';
  }
  for (int i = m - 1; i >= 0; --i) {
    am[i] = b[m - i - 1] - '0';
  }
  for (int i = 0; i < m; ++i) {
    if (am[m - 1 - i] == 1) {
      cnt++;
    }
    c[m - 1 - i] = cnt;
  }
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    if (an[i] == 1) {
      sum += (arr[i] * c[i]) % MOD;
    }
  }
  cout << sum << endl;
}
