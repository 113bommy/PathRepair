#include <bits/stdc++.h>
using namespace std;
struct S {
  long long prime;
  int q, h, ji;
};
S xxx[300000];
priority_queue<S> sum[4];
bool biao[300000];
bool operator<(const S &a, const S &b) { return a.prime > b.prime; }
int main() {
  int x, y;
  scanf("%d", &x);
  for (int a = 0; a < x; a++) {
    scanf("lld", &xxx[a].prime);
    xxx[a].ji = a;
  }
  for (int a = 0; a < x; a++) scanf("%d", &xxx[a].q);
  for (int a = 0; a < x; a++) scanf("%d", &xxx[a].h);
  for (int a = 0; a < x; a++) {
    sum[xxx[a].q].push(xxx[a]);
    sum[xxx[a].h].push(xxx[a]);
  }
  scanf("%d", &y);
  while (y--) {
    scanf("%d", &x);
    while (!sum[x].empty() && biao[sum[x].top().ji]) sum[x].pop();
    if (sum[x].empty())
      printf("-1");
    else {
      printf("%lld", sum[x].top().prime);
      biao[sum[x].top().ji] = 1;
      sum[x].pop();
    }
    printf("%c", y == 0 ? '\n' : ' ');
  }
  return 0;
}
