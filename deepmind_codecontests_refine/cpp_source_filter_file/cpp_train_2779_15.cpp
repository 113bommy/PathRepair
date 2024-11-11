#include <bits/stdc++.h>
using namespace std;
char s[20], st[20], sst[20];
int t[10], n;
int vis[10];
long long a[20];
long long sum = 0;
map<string, int> mapp;
void dfs(bool flag, int x) {
  for (int i = 0; i < x; i++) {
    sst[i] = st[i];
  }
  sst[x] = '\0';
  sort(sst, sst + x);
  if (mapp[sst]) {
    return;
  }
  mapp[sst] = 1;
  long long b = a[x];
  for (int i = 0; i < 9; i++) {
    if (vis[i]) {
      b /= a[vis[i]];
    }
  }
  if (flag && x != 1) {
    vis[0]--;
    long long c = a[x - 1];
    for (int i = 0; i < 9; i++) {
      if (vis[i]) {
        c /= a[vis[i]];
      }
    }
    vis[0]++;
    b -= c;
  }
  sum += b;
  if (x == n) return;
  for (int i = 0; i < 9; i++) {
    if (t[i] > vis[i]) {
      vis[i]++;
      st[x] = '0' + i, dfs(flag, x + 1);
      vis[i]--;
    }
  }
}
int main() {
  a[0] = 1;
  for (int i = 1; i <= 19; i++) {
    a[i] = a[i - 1] * i;
  }
  scanf("%s", s);
  n = strlen(s);
  bool flag = false;
  int m = 0;
  for (int i = 0; i < n; i++) {
    t[s[i] - '0']++;
    if (vis[s[i] - '0'] == 0) {
      vis[s[i] - '0'] = 1;
      if (s[i] - '0' == 0) flag = true;
      st[m++] = s[i];
    }
  }
  dfs(flag, m);
  printf("%lld\n", sum);
  return 0;
}
