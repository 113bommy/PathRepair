#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const int N = 4000;
const int M = 300;
const long long MOD = 1000000007;
int d[4000][4000];
long long D;
const int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
const int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};
bool bound(int x, int y) { return !(x < 0 || x >= N || y < 0 || y >= N); }
int Gres, n;
void bfs() {
  queue<int> q;
  q.push(2000);
  q.push(2000);
  d[2000][2000] = 0;
  while (q.size()) {
    Gres++;
    int x = q.front();
    q.pop();
    int y = q.front();
    q.pop();
    if (d[x][y] == min(D, (long long)M + 5)) continue;
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!bound(nx, ny) || d[nx][ny] != -1) continue;
      d[nx][ny] = d[x][y] + 1;
      q.push(nx);
      q.push(ny);
    }
  }
}
long long Zn(long long x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}
long long Pow(long long a, long long x) {
  if (x == 0) return 1;
  if (x == 1) return a;
  long long t = Pow(a, x / 2);
  t = (t * t) % MOD;
  return (t * Pow(a, x % 2)) % MOD;
}
int main() {
  memset(d, -1, sizeof(d));
  ;
  scanf("%I64d%d", &D, &n);
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    d[a + 2000][b + 2000] = -2;
  }
  if (D < 200) {
    bfs();
    printf("%d\n", Gres);
    return 0;
  }
  long long res = 0;
  bfs();
  long long cntM = 0, cntM1 = 0, cntM2 = 0, cnt = 0;
  for (int i = 0; i < 4000; i++) {
    for (int j = 0; j < 4000; j++) {
      if (d[i][j] == M) cntM++;
      if (d[i][j] == M - 1) cntM1++;
      if (d[i][j] == M - 2) cntM2++;
      if (d[i][j] < M && d[i][j] >= 0) cnt++;
    }
  }
  cnt %= MOD;
  cnt += ((D - M + 1) % MOD) * cntM;
  cnt %= MOD;
  unsigned long long tcnt = 1;
  tcnt *= (cntM1 - cntM2);
  tcnt *= (D - M + 1) % MOD;
  tcnt %= MOD;
  tcnt *= (D - M) % MOD;
  tcnt %= MOD;
  tcnt *= Pow(2, MOD - 2);
  tcnt %= MOD;
  cnt += tcnt;
  cnt %= MOD;
  printf("%I64d\n", cnt);
  return 0;
}
