#include <bits/stdc++.h>
using namespace std;
const int N = 50003;
vector<int> ans;
pair<unsigned short, unsigned short> f[32][32][N];
int trans[N][33];
int n, p;
int a[N];
inline int go(int a, int x) {
  if (x < 10)
    return (a * 10 + x) % p;
  else
    return (a * 100 + x) % p;
}
void gao(int i, int j, int k) {
  if (f[i][j][k].first > 0) {
    ans.push_back(i);
    if (f[i][j][k].first == 1) gao(i - 1, j ^ a[i], f[i][j][k].second);
  } else if (f[i][j][k].first == 0)
    gao(i - 1, j, k);
}
int main() {
  static int pos[33];
  cin >> n >> p;
  int t = 0;
  for (int i = 1, _ = n; i <= _; i++) {
    cin >> a[i];
    if (a[i] <= 31) a[++t] = a[i], pos[t] = i;
  }
  n = t;
  memset(f, -1, sizeof f);
  for (int i = 0, _ = p - 1; i <= _; i++)
    for (int j = 1, _ = n; j <= _; j++) {
      int x = go(i, a[j]);
      trans[i][j] = x;
    }
  for (int i = 1, _ = n; i <= _; i++) {
    f[i][a[i]][trans[0][i]] = make_pair(2, 0);
    for (int j = 0, _ = 31; j <= _; j++)
      for (int k = 0, _ = p - 1; k <= _; k++)
        if (f[i - 1][j][k].second < p) {
          f[i][j ^ a[i]][trans[k][i]] = make_pair(1, k);
          f[i][j][k] = make_pair(0, k);
        }
  }
  for (int i = 1, _ = n; i <= _; i++)
    if (f[i][0][0].second < p) {
      puts("Yes");
      gao(n, 0, 0);
      reverse(ans.begin(), ans.end());
      cout << ans.size() << endl;
      for (int v : ans) cout << pos[v] << " ";
      cout << endl;
      return 0;
    }
  puts("No");
  return 0;
}
