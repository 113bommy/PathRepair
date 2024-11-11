#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int MAXN = 2e5 + 10;
const double eps = 1e-8;
const long long mod = 1e8;
int a[maxn], cnt[maxn];
int ans[maxn];
vector<pair<int, int> > v;
int n, k;
bool cmp(pair<int, int> a, pair<int, int> b) { return (a.second) > (b.second); }
bool check(int t) {
  int num = 0;
  vector<pair<int, int> >::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    int temp = (*it).second / t;
    num += temp;
    if (num > k) break;
  }
  if (num >= k) return true;
  return false;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  for (int i = 1; i < maxn; i++) {
    if (cnt[i] > 0) v.push_back(make_pair(i, cnt[i]));
  }
  sort(v.begin(), v.end(), cmp);
  int l = 0, r = maxn;
  while (r - l > 1) {
    int mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  int t = l;
  int idx = 0;
  vector<pair<int, int> >::iterator it;
  int num = 0;
  for (it = v.begin(); it != v.end(); it++) {
    int temp = (*it).second / t;
    num += temp;
    for (int i = 0; i < temp; i++) ans[idx++] = (*it).first;
    if (num > k) break;
  }
  printf("%d", ans[0]);
  for (int i = 1; i < k; i++) printf(" %d", ans[i]);
  return 0;
}
