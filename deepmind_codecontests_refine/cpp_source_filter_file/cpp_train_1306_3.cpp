#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void boost() { ios_base::sync_with_stdio(0); }
int n, m, sum;
char s[1001][1001];
int v[1001];
int u[1001];
int main() {
  boost();
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
      if (s[i][j] == '*') {
        sum++;
        v[i]++;
        u[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum2 = v[i] + u[j];
      if (s[i][j] == '*') {
        sum2++;
      }
      if (sum2 == sum) {
        cout << "YES\n" << i + 1 << " " << j + 1, exit(0);
      }
    }
  }
  cout << "NO";
  exit(0);
}
