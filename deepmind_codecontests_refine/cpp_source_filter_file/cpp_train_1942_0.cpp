#include <bits/stdc++.h>
using namespace std;
long long ans[100000];
int top = 0;
int cnt = 10000;
void deal(long long p, long long k) {
  cnt--;
  if (!cnt) return;
  if (p >= 0 && p <= k) return void(ans[top] = p);
  if (p >= 0) {
    long long w = p / k;
    ans[top++] = p - w * k;
    deal(-w, k);
  } else {
    long long w = (-p) / k + 1;
    if (p + w * k >= k) w--;
    ans[top++] = p + w * k;
    deal(w, k);
  }
}
int main() {
  long long k, p;
  cin >> p >> k;
  deal(p, k);
  if (!cnt) puts("-1");
  printf("%d\n", top + 1);
  for (int i = 0; i <= top; i++) printf("%d ", ans[i]);
}
