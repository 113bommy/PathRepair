#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
vector<int> ask[maxn];
long long ans[maxn];
int num[maxn];
void query(vector<int> v, int pos) {
  if (v.size() == 0) return;
  printf("? %d", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf(" %d", v[i]);
  }
  printf("\n");
  fflush(stdout);
  scanf("%lld", &ans[pos]);
}
int tot(int x) {
  int ret;
  ret = 0;
  while (x) {
    if (x % 2) ret++;
    x /= 2;
  }
  return ret;
}
int main() {
  int T, flag, ret, n, m, cnt;
  scanf("%d", &n);
  m = 13;
  cnt = 0;
  for (int i = 1; i <= (1 << m) - 1; i++) {
    if (tot(i) == 6) {
      num[++cnt] = i;
      for (int j = 1; j <= 13; j++) {
        if ((i & (1 << (j - 1))) == 0) {
          ask[j].push_back(cnt);
        }
      }
    }
    if (cnt == n) break;
  }
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= 13; i++) {
    query(ask[i], i);
  }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    long long ret = 0;
    for (int j = 1; j <= 13; j++) {
      if (num[i] & (1 << (j - 1))) {
        ret |= ans[j];
      }
    }
    printf("%lld ", ret);
  }
  printf("\n");
  return 0;
}
