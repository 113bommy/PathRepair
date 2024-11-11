#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e5 + 5;
char a[20][MAXN];
int des;
int n, m;
int d[20][2];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i]);
  }
  d[n + 1][1] = INF;
  int des = n;
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < m + 2; j++) {
      if (a[i][j] == '1') {
        des = i;
      }
    }
  }
  for (int i = n; i >= des + 1; i--) {
    int fir = m + 1, last = 0;
    for (int j = 0; j < m + 2; j++) {
      if (a[i][j] == '1') {
        if (fir == m + 1) {
          fir = j;
        }
        last = j;
      }
    }
    d[i][0] = min(d[i + 1][0] + (last + 1) * 2 - 1, d[i + 1][1] + m + 2);
    d[i][1] = min(d[i + 1][1] + (m + 2 - fir) * 2 - 1, d[i + 1][0] + m + 2);
  }
  int ans = 0;
  int fir = m + 1, last = 0;
  for (int i = 0; i < m + 2; i++) {
    if (a[des][i] == '1') {
      if (fir == m + 1) {
        fir = i;
      }
      last = i;
    }
  }
  ans = min(d[des + 1][0] + last, d[des + 1][1] + m + 2 - fir - 1);
  cout << ans << endl;
}
