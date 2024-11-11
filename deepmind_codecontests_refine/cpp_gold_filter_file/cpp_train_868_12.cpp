#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:16000000")
const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 2 * acos(0.);
char tmp[6000000];
int days[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int t[6000000];
char ans[6000000][5];
void print(int i) {
  printf("2012-%02d-%02d %02d:%02d:%02d\n", (int)ans[i][0], (int)ans[i][1],
         (int)ans[i][2], (int)ans[i][3], (int)ans[i][4]);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int M, D, HH, MM, SS;
  int N = 0;
  while (scanf("%*d-%d-%d %d:%d:%d:", &M, &D, &HH, &MM, &SS) > 0) {
    gets(tmp);
    ans[N][0] = M;
    ans[N][1] = D;
    ans[N][2] = HH;
    ans[N][3] = MM;
    ans[N][4] = SS;
    int T = 0;
    for (int i = 0; i + 1 < M; ++i) {
      T += days[i];
    }
    T += D;
    T *= 24;
    T += HH;
    T *= 60;
    T += MM;
    T *= 60;
    T += SS;
    t[N++] = T;
  }
  int p1 = 0;
  int p2 = 0;
  for (; p2 < N; ++p2) {
    while (t[p2] - t[p1] >= n) {
      ++p1;
    }
    if (p2 - p1 + 1 >= m) {
      print(p2);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
