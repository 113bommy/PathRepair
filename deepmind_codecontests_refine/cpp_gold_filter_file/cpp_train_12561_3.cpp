#include <bits/stdc++.h>
using namespace std;
int N = 0, A = 0, B = 0;
struct Node {
  long long hp, dmg;
  bool operator<(const Node &A) const { return hp - dmg > A.hp - A.dmg; }
} creature[200005];
int main() {
  scanf("%d%d%d", &N, &A, &B);
  for (int i = 0; i < N; i++)
    scanf("%lld%lld", &creature[i].hp, &creature[i].dmg);
  long long ans = 0, ptr = -1, res = 0;
  sort(creature, creature + N);
  for (int i = 0; i < N; i++) {
    if (creature[i].hp <= creature[i].dmg || i >= B)
      ans += creature[i].dmg;
    else
      ans += (creature[i].hp), ptr = i;
  }
  res = ans;
  for (int i = 0; i < N; i++) {
    if (B <= 0 || A <= 0) break;
    if (i <= ptr)
      res = max(res, ans + (creature[i].hp << A) - creature[i].hp);
    else if (B != ptr + 1)
      res = max(res, ans + (creature[i].hp << A) - creature[i].dmg);
    else
      res = max(res, ans - (creature[ptr].hp - creature[ptr].dmg) +
                         (creature[i].hp << A) - creature[i].dmg);
  }
  printf("%lld\n", res);
  return 0;
}
