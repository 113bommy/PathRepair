#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 2;
int card[MAXN][2];
int amount[2][MAXN];
int record[MAXN * 2];
int N, P;
void discre(int &x) {
  int l = 1, mid = 1, r = P;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (record[mid] == x) break;
    if (record[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  assert(record[mid] == x);
  x = mid;
  return;
}
void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &card[i][0], &card[i][1]);
    record[i + i - 1] = card[i][0];
    record[i + i] = card[i][1];
  }
  sort(&record[1], &record[N * 2 + 1]);
  P = unique(&record[1], &record[N * 2 + 1]) - &record[1];
  for (int i = 1; i <= N; ++i) {
    discre(card[i][0]);
    discre(card[i][1]);
  }
}
int main() {
  init();
  for (int i = 1; i <= N; ++i) {
    ++amount[0][card[i][0]];
    if (card[i][0] != card[i][1]) ++amount[1][card[i][1]];
  }
  int need = (N + 1) >> 1;
  int cost = INT_MAX;
  for (int i = 1; i <= P; ++i) {
    if (amount[0][i] + amount[1][i] >= need)
      cost = min(cost, need - amount[0][i]);
  }
  cost = max(cost, 0);
  if (cost == INT_MAX) cost = -1;
  printf("%d\n", cost);
  return 0;
}
