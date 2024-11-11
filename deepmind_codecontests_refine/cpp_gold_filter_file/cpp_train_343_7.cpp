#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500030;
struct node {
  long long num;
  long long val;
} pen[maxn], tot[maxn];
vector<node> vec[5000];
long long n, k, ci, ti;
int cmp(struct node& a, struct node& b) { return a.val > b.val; }
double sum = 0;
long long cnt1, cnt2;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ci >> ti;
    sum += ci;
    if (ti == 1) {
      tot[cnt1].val = ci;
      tot[cnt1].num = i;
      cnt1++;
    } else {
      pen[cnt2].val = ci;
      pen[cnt2].num = i;
      cnt2++;
    }
  }
  sort(tot, tot + cnt1, cmp);
  sort(pen, pen + cnt2, cmp);
  int cnt = 1;
  for (int i = 0; i < cnt1; i++) {
    vec[cnt].push_back(tot[i]);
    if (cnt != k) cnt++;
  }
  if (cnt1 < k) {
    for (int i = 0; i < cnt1; i++) {
      sum -= tot[i].val / 2.0;
    }
    int ss = 0;
    for (int i = cnt1 + 1; i < k; i++) {
      vec[i].push_back(pen[ss]);
      ss++;
    }
    for (int i = ss; i < cnt2; i++) {
      vec[k].push_back(pen[i]);
    }
  } else {
    for (int i = 0; i < k - 1; i++) {
      sum -= tot[i].val / 2.0;
    }
    if (cnt1 != 0 && cnt2 != 0)
      sum -= min(tot[cnt1 - 1].val, pen[cnt2 - 1].val) / 2.0;
    if (cnt2 == 0) sum -= tot[cnt1 - 1].val / 2.0;
    for (int i = 0; i < cnt2; i++) {
      vec[k].push_back(pen[i]);
    }
  }
  printf("%.1lf\n", sum);
  for (int i = 1; i <= k; i++) {
    printf("%d", vec[i].size());
    for (int j = 0; j < vec[i].size(); j++) {
      printf(" %lld", vec[i][j].num);
    }
    printf("\n");
  }
  return 0;
}
