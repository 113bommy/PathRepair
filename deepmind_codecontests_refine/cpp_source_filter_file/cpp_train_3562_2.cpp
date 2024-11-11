#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
int N, K;
char s[MAX];
int col[MAX][3], pre[MAX << 1], siz[MAX << 1], ans;
int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
void merge(int x, int y) {
  x = find(x), y = find(y);
  if (x != y) pre[x] = y, siz[y] += siz[x];
}
int calc(int x) { return min(siz[find(x)], siz[find(x + K)]); }
void solve(int i) {
  int cnt = col[i][0];
  if (cnt == 2) {
    int x = col[i][1], y = col[i][2];
    if (s[i] == '1') {
      if (find(x) == find(y)) return;
      ans -= calc(x) + calc(y);
      merge(x, y), merge(x + K, y + K);
      ans += calc(x);
    } else {
      if (find(x) == find(y + K)) return;
      ans -= calc(x) + calc(y);
      merge(x, y + K), merge(x + K, y);
      ans += calc(x);
    }
  } else if (cnt == 1) {
    int x = col[i][1];
    if (s[i] == '1') {
      if (find(x) == find(0)) return;
      ans -= calc(x);
      merge(x, 0);
      ans += calc(x);
    } else {
      if (find(x + K) == find(0)) return;
      ans -= calc(x);
      merge(x + K, 0);
      ans += calc(x);
    }
  }
}
int main() {
  scanf("%d%d%s", &N, &K, s + 1);
  for (int i = 1; i <= K; i++) {
    int c;
    scanf("%d", &c);
    for (int j = 1; j <= c; j++) {
      int x;
      scanf("%d", &x);
      col[x][++col[x][0]] = i;
    }
  }
  for (int i = 1; i <= (1 << K); i++) pre[i] = i, siz[i] = i <= K;
  siz[0] = 1e9;
  for (int i = 1; i <= N; i++) {
    solve(i);
    printf("%d\n", ans);
  }
  return 0;
}
