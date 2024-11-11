#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int M = 1e5 + 5;
char s[M];
int A[M];
int sum[M], sum1[M];
vector<int> edge[M];
void dfs(int x, int y) {
  int ok = 1;
  for (int to : edge[x]) {
    if (y == to) continue;
    ok = 0;
    dfs(to, x);
    if (x > 5) {
      sum[x] += sum[to];
      sum1[x] += sum1[to];
    } else {
      sum[x] = max(sum[to], sum[x]);
      sum1[x] = max(sum1[to], sum1[x]);
    }
  }
  if (ok)
    sum1[x] = 1;
  else
    sum[x]++;
}
map<string, int> mp[M];
int main() {
  int ans1 = 0, ans2 = 0;
  for (char j = 'C'; j <= 'G'; j++) {
    string now;
    now += j;
    mp[M - 1][now] = j - 'C';
  }
  int strno = 5;
  while (scanf("%s", s) != EOF) {
    int n = strlen(s);
    int pre = s[0] - 'C';
    for (int j = 3; j < n; j++) {
      int nxt = n;
      int ok = 1;
      string now = "";
      for (int k = j; k < n; k++) {
        if (s[k] == '\\') {
          nxt = k;
          break;
        }
        now += s[k];
      }
      if (!mp[pre][now]) {
        mp[pre][now] = strno++;
        edge[pre].push_back(strno - 1);
      }
      pre = mp[pre][now];
      j = nxt;
    }
  }
  for (int j = 0; j <= 4; j++) {
    dfs(j, -1);
    ans1 = max(ans1, sum[j] - 2);
    ans2 = max(ans2, sum1[j]);
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
