#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double EPS = 1e-10;
const int N = 1e3 + 1;
const int MOD = 1e9 + 7;
bool a[N][N];
char s[N], t[N];
int main() {
  int n, m, mn = MOD;
  cin >> n >> m;
  cin >> s + 1;
  cin >> t + 1;
  int j = 0, cnt = 0, k = 0, l = 0;
  for (int i = 1; i <= m - n + 1; i++) {
    j = i - 1;
    k = 0;
    cnt = 0;
    while (k <= n) {
      k++;
      j++;
      if (s[k] != t[j]) {
        cnt++;
      }
    }
    if (cnt < mn) {
      mn = cnt;
      l = i;
    }
  }
  cout << mn << endl;
  k = 0;
  for (int i = l; i < l + n; i++) {
    k++;
    if (s[k] != t[i]) {
      cout << k << " ";
    }
  }
  return 0;
}
