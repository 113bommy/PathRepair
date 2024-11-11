#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 5e2 + 5, M = 5e3 + 5;
int nextmod[N][M], nextsum[N][M], vis[N][M];
char dig[N][M];
queue<pair<int, int> > q;
int d, s;
void print_ans(int mod, int sum) {
  if (mod == -1) return;
  print_ans(nextmod[mod][sum], nextsum[mod][sum]);
  printf("%c", dig[mod][sum]);
}
int main() {
  scanf("%d%d", &d, &s);
  memset((nextmod), (-1), sizeof(nextmod));
  memset((nextsum), (-1), sizeof(nextsum));
  for (int i = 1; i < s and i < 10; i++) {
    q.push({i % d, i});
    dig[i % d][i] = i + '0';
    vis[i % d][i] = 1;
  }
  while (!q.empty()) {
    int mod = q.front().first, sum = q.front().second;
    if (mod == 0 and sum == s) {
      print_ans(mod, s);
      printf("\n");
      return 0;
    }
    q.pop();
    for (int i = 0; i < 10; i++) {
      int nmod = (mod * 10 + i) % d, nsum = sum + i;
      if (nsum > s) break;
      if (vis[nmod][nsum]) continue;
      nextmod[nmod][nsum] = mod;
      nextsum[nmod][nsum] = sum;
      vis[nmod][nsum] = 1;
      dig[nmod][nsum] = '0' + i;
      q.push({nmod, nsum});
    }
  }
  printf("-1\n");
  return 0;
}
