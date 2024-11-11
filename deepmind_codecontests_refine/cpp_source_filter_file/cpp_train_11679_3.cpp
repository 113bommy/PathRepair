#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n;
pair<int, int> Cd[N + 10];
int cop[2 * N + 10], lnk[2 * N + 10];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &Cd[i].first), Cd[i].second = i * 2 - 1;
  sort(Cd + 1, Cd + 1 + n);
  int L = 1, R = n, LEN = Cd[n].first;
  cop[1] = Cd[n].second;
  cop[++LEN] = Cd[n].second + 1;
  int I = n - 1;
  for (int i = n - 1, j = 2; i >= 1 && j <= Cd[n].first; I = --i, j++) {
    int u = Cd[i].second, v = u + 1;
    cop[j] = u;
    lnk[u] = -1;
    if (j + Cd[i].first > LEN) {
      LEN++;
      cop[LEN] = v;
      lnk[v] = -1;
    } else
      lnk[v] = j + Cd[i].first;
  }
  for (int i = I; i >= 1; i--) {
    int u = Cd[i].second, v = u + 1;
    if (Cd[i].first == 1) {
      lnk[u] = lnk[v] = -1;
      printf("%d %d\n", cop[1], u);
      printf("%d %d\n", u, v);
    } else {
      lnk[u] = 1;
      lnk[v] = 1 + (Cd[i].first - 2);
    }
  }
  for (int i = 2; i <= LEN; i++) printf("%d %d\n", cop[i], cop[i - 1]);
  for (int i = 1; i <= 2 * n; i++)
    if (lnk[i] > 0) printf("%d %d\n", i, cop[lnk[i]]);
  return 0;
}
