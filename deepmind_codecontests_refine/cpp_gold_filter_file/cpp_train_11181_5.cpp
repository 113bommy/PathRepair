#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int dis[27][27], mp[27][27];
char s1[maxn], s2[maxn], a1, a2, s3[maxn];
void floyd() {
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) dis[i][j] = mp[i][j];
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
  int n, w;
  cin >> s1 >> s2 >> n;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++) {
      if (i == j)
        mp[i][j] = 0;
      else
        mp[i][j] = 0x3f3f3f3f;
    }
  for (int i = 1; i <= n; i++) {
    cin >> a1 >> a2 >> w;
    int u = a1 - 'a', v = a2 - 'a';
    mp[u][v] = min(mp[u][v], w);
  }
  floyd();
  int len1 = strlen(s1), len2 = strlen(s2);
  if (len1 != len2) {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < len1; i++) {
    if (s1[i] == s2[i]) {
      s3[i] = s1[i];
      continue;
    } else {
      int mini = 0x3f3f3f3f, x = -1, u = s1[i] - 'a', v = s2[i] - 'a';
      for (int j = 0; j < 26; j++) {
        if (dis[u][j] + dis[v][j] < mini) mini = dis[u][j] + dis[v][j], x = j;
      }
      if (x == -1) {
        cout << "-1" << endl;
        return 0;
      } else {
        s3[i] = x + 'a';
        ans += mini;
      }
    }
  }
  cout << ans << endl;
  cout << s3 << endl;
  return 0;
}
