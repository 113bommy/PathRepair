#include <bits/stdc++.h>
static const int MAXN = 110;
static const int MAXM = 110;
bool boys[MAXN], girls[MAXM];
int main() {
  int N, M;
  std::scanf("%d %d", &N, &M);
  int hb;
  std::scanf("%d", &hb);
  for (int i = 0; i < hb; i++) {
    int pos;
    std::scanf("%d", &pos);
    boys[pos] = true;
  }
  int hg;
  std::scanf("%d", &hg);
  for (int i = 0; i < hg; i++) {
    int pos;
    std::scanf("%d", &pos);
    girls[pos] = true;
  }
  for (int day = 0; day < N * M; day++) {
    bool b = boys[day % N];
    bool g = girls[day % M];
    if (b || g) boys[day % N] = girls[day % M] = true;
  }
  bool good = true;
  for (int i = 0; i < N; i++) {
    if (!boys[i]) {
      good = false;
      break;
    }
  }
  if (!good) {
    std::printf("No\n");
    return 0;
  }
  for (int i = 0; i < M; i++) {
    if (!girls[i]) {
      good = false;
      break;
    }
  }
  if (!good) {
    std::printf("No\n");
    return 0;
  }
  std::printf("Yes\n");
  return 0;
}
