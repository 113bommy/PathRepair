#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 7;
const long double pi = 3.14159265359;
const long long INF = 1e9 + 7;
const long long EN = 1e5 + 7;
int n, m, a[N], b[N], ans[N], pr1[N], pr2[N], j, p[N], cnt;
int main() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  ;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  for (int i = 0; i < m - 1; i++) {
    pr2[i] = b[i + 1] - b[i];
    ans[i] = pr2[i];
  }
  ans[m - 1] = INF;
  for (int i = 0; i < n - 1; i++) {
    pr1[i] = a[i + 1] - a[i];
    ans[m + i] = pr1[i];
  }
  for (int i = 1; i < n + m - 1; i++) {
    j = p[i - 1];
    while (j > 1 && ans[i] != ans[j]) {
      j = p[j - 1];
    }
    if (ans[i] == ans[j]) {
      j++;
    }
    p[i] = j;
  }
  for (int i = 0; i < n + m - 1; i++) {
    if (p[i] == m - 1) {
      cnt++;
    }
  }
  cout << cnt;
}
