#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MAX = 1e6 + 10;
int a[100005];
int b[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, m, sum, t, len;
  string s, d;
  while (cin >> n >> t) {
    int flag = 0;
    sum = 0;
    k = 0;
    for (int i = 1; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i = a[i] + i) {
      if (t == i) {
        flag = 1;
        break;
      }
      if (i == n) break;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
