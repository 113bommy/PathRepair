#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
bool in[maxn], leader[maxn], first[maxn], vis[maxn];
char cmd[maxn];
int id[maxn];
char buf[1000];
int incnt, ans;
int main() {
  int n, m, dcnt = 0;
  cin >> n >> m;
  ans = -1;
  for (int i = 1; i <= m; i++) {
    scanf("%s%d", &buf, &id[i]);
    cmd[i] = buf[0];
    if (cmd[i] == '-' && first[id[i]] == false) {
      incnt++;
      in[id[i]] = true;
    }
    first[id[i]] = true;
  }
  for (int i = 1; i <= m; i++) {
    if (cmd[i] == '+') {
      if (incnt == 0)
        ans = (ans == -1 || ans == id[i]) ? id[i] : -2;
      else if (id[i] == ans)
        ans = -2;
      else
        leader[i] = true;
      vis[id[i]] = true;
      incnt++;
    } else {
      if (incnt == 1)
        ans = (ans == -1 || ans == id[i]) ? id[i] : -2;
      else if (id[i] == ans)
        ans = -2;
      else
        leader[i] = true;
      vis[id[i]] = true;
      incnt--;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if ((i == ans || !vis[i]) && !leader[i]) cnt++;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++)
    if ((i == ans || !vis[i]) && !leader[i]) cout << i << " ";
  if (cnt != 0) cout << endl;
  return 0;
}
