#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, p[maxn];
int _cnt[maxn * 5], *cnt;
long long suma, sumb;
int cnta, cntb;
void insert(int x) {
  ++cnt[x];
  if (x > 0) {
    suma += x;
    ++cnta;
  } else {
    sumb -= x;
    ++cntb;
  }
}
void remove(int x) {
  --cnt[x];
  if (x > 0) {
    suma -= x;
    --cnta;
  } else {
    sumb += x;
    --cntb;
  }
}
int main(void) {
  scanf("%d", &n);
  cnt = _cnt + maxn * 2;
  for (int i = 0; i < n; ++i) {
    scanf("%d", p + i);
    --p[i];
    insert(p[i] - i);
  }
  int ans = 0;
  long long best = suma + sumb;
  for (int k = 1; k < n; ++k) {
    remove(p[n - k] - (n - 1));
    suma -= cnta;
    sumb += cntb;
    cnta -= cnt[1];
    cntb += cnt[1];
    ++cnt;
    insert(p[n - k] - 0);
    long long tmp = suma + sumb;
    if (tmp < best) {
      best = tmp;
      ans = k;
    }
  }
  printf("%lld %d\n", best, ans);
  return 0;
}
