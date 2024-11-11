#include <bits/stdc++.h>
using namespace std;
const int Inf = 20000000 + 1901;
const int MAXN = 2 * 1e5;
int n, l = Inf, me = -Inf, sum = 0;
pair<int, int> A[MAXN];
bool inf = 1;
void update1() { me = max(me, 1900 - sum); }
void update2() { l = min(1900 - sum, l); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &A[i].first, &A[i].second);
  for (int i = 0; i < n; i++) {
    if (A[i].second == 1)
      update1();
    else
      update2();
    sum += A[i].first;
    if (A[i].second != 1) inf = 0;
  }
  if (l < me)
    printf("Impossible");
  else {
    if (inf)
      printf("Infinity");
    else
      printf("%d", (l - 1) + sum);
  }
}
