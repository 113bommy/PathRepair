#include <bits/stdc++.h>
struct card {
  int a, b;
  bool operator<(const card &x) const {
    if (b == x.b) return a > x.a;
    return b > x.b;
  }
} cards[1000];
int n, i, score = 0, rem = 1;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d%d", &cards[i].a, &cards[i].b);
  std::sort(cards, cards + n);
  for (i = 0; rem > 0 && i < n; ++i) {
    --rem;
    score += cards[i].a;
    rem += cards[i].b;
  }
  printf("%d\n", score);
  return 0;
}
