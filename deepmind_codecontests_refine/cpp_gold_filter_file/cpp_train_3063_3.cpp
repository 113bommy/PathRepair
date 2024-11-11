#include <bits/stdc++.h>
using namespace std;
vector<int> S;
vector<int> ack;
int pop[1100100];
int kol[1100100];
int k[1234];
char c[1234];
const int INF = 1000000000;
int parse(int a) {
  if (a == INF) return -INF;
  return a;
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = (0); i <= (int(n) - 1); ++i) {
    int s;
    scanf("%d", &s);
    S.push_back(s);
  }
  sort(S.begin(), S.end());
  scanf("%d", &m);
  for (int i = (0); i <= (int(m) - 1); ++i) {
    ack.push_back(S.back());
    S.pop_back();
  }
  for (int i = (0); i <= (int(m) - 1); ++i) {
    scanf(" %c%d", &c[i], &k[i]);
  }
  for (int q = m - 1; q >= 0; q--) {
    for (int i = (0); i <= (int(1 << m) - 1); ++i) pop[i] = kol[i];
    int mn = 1;
    if (k[q] == 2) mn *= -1;
    for (int i = (0); i <= (int(1 << m) - 1); ++i) {
      kol[i] = -INF;
      for (int j = (0); j <= (int(m) - 1); ++j)
        if ((i & (1 << j)) != 0) {
          int x = ack[j];
          if (c[q] == 'b') x = 0;
          kol[i] =
              mn * max(mn * (pop[i ^ (1 << j)] + mn * x), parse(kol[i] * mn));
        }
    }
  }
  printf("%d\n", kol[(1 << m) - 1]);
}
