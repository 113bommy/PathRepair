#include <bits/stdc++.h>
using namespace std;
int n, ch[100005][2], dis[100005], ans;
int l[100005], r[100005], root;
bool if_[100005];
map<int, int> ma;
map<int, bool> maa;
inline void in(int &now) {
  int if_z = 1;
  now = 0;
  char Cget = getchar();
  while (Cget > '9' || Cget < '0') {
    if (Cget == '-') if_z = -1;
    Cget = getchar();
  }
  while (Cget >= '0' && Cget <= '9') {
    now = now * 10 + Cget - '0';
    Cget = getchar();
  }
  now *= if_z;
}
void dfs(int now, int l, int r) {
  if (l > r) return;
  if (dis[now] >= l || dis[now] <= r) {
    if (!maa[dis[now]]) {
      ans += ma[dis[now]];
      maa[dis[now]] = true;
    }
  }
  if (ch[now][0] != -1) dfs(ch[now][0], l, min(dis[now] - 1, r));
  if (ch[now][1] != -1) dfs(ch[now][1], max(l, dis[now] + 1), r);
}
int main() {
  in(n);
  for (int i = 1; i <= n; i++) {
    in(dis[i]), in(ch[i][0]), in(ch[i][1]), ma[dis[i]]++;
    if (ch[i][0] != -1) if_[ch[i][0]] = true;
    if (ch[i][1] != -1) if_[ch[i][1]] = true;
  }
  for (int i = 1; i <= n; i++) {
    if (!if_[i]) {
      root = i;
      break;
    }
  }
  dfs(root, 0, 0x7fffffff);
  cout << n - ans;
  return 0;
}
