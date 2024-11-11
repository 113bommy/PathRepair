#include <bits/stdc++.h>
using namespace std;
char len[110][110];
int dis[110][110];
int visit[110];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) scanf("%s", len[i]);
    long long sum, tot;
    tot = 1;
    for (int i = 0; i < m; i++) {
      memset(visit, 0, sizeof(visit));
      sum = 0;
      for (int j = 0; j < n; j++) {
        if (!visit[len[j][i] - 'A']) {
          sum++;
          visit[len[j][i] - 'A'] = 1;
        }
      }
      tot *= sum;
      tot %= 1000000007;
    }
    cout << tot << endl;
  }
}
