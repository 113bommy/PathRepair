#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 100;
const int md = 1000000007;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int t, n, m, ans[30][5];
  vector<string> arr(2010), ars(2010);
  cin >> t;
  pair<int, int> awal[30], akhir[30];
  while (t--) {
    bool can = true, hidup[30] = {};
    int p = -1;
    cin >> n >> m;
    for (int i = 0; i < 27; i += 1) awal[i].first = -1;
    for (int i = 0; i < n; i += 1) {
      cin >> arr[i];
      ars[i] = arr[i];
      for (int j = 0; j < m; j += 1) {
        ars[i][j] = '.';
        if (arr[i][j] != '.') {
          int z = arr[i][j] - 'a';
          hidup[z] = 1;
          if (awal[z].first == -1) awal[z] = make_pair(i, j);
          akhir[z] = make_pair(i, j);
        }
      }
    }
    for (int i = 0; i < 26; i += 1) {
      if (hidup[i]) p = i;
    }
    for (int i = 0; i < p + 1; i += 1) {
      if (hidup[i] == 0) continue;
      int a = awal[i].first, b = awal[i].second;
      int c = akhir[i].first, d = akhir[i].second;
      if (a == c) {
        for (int j = b; j < d + 1; j += 1) ars[a][j] = char(i + 'a');
      } else if (b == d) {
        for (int j = a; j < c + 1; j += 1) ars[j][b] = char(i + 'a');
      }
      ans[i][0] = a + 1;
      ans[i][1] = b + 1;
      ans[i][2] = c + 1;
      ans[i][3] = d + 1;
    }
    for (int i = 0; i < p + 1; i += 1) {
      if (hidup[i]) continue;
      ans[i][0] = ans[p][0];
      ans[i][1] = ans[p][1];
      ans[i][2] = ans[p][2];
      ans[i][3] = ans[p][3];
    }
    for (int i = 0; i < n; i += 1) {
      for (int j = 0; j < m; j += 1)
        if (arr[i][j] != ars[i][j]) can = false;
    }
    if (can) {
      printf("YES\n%d\n", p + 1);
      for (int i = 0; i < p + 1; i += 1) {
        for (int j = 0; j < 4; j += 1) printf("%d ", ans[i][j]);
        printf("\n");
      }
    } else
      printf("NO\n");
  }
}
