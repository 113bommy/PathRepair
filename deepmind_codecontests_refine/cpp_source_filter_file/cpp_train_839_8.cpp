#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 1000;
long long re[maxn];
vector<long long> v;
int sum[maxn];
struct node {
  long long l, r;
} a[maxn];
long long ans[maxn];
int getid(long long x) {
  return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a[i].l, &a[i].r);
    v.push_back(a[i].l);
    v.push_back(a[i].r);
    v.push_back(a[i].l + 1);
    v.push_back(a[i].r + 1);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int sz = v.size();
  for (int i = 0; i < v.size(); i++) {
    re[i + 1] = v[i];
  }
  for (int i = 0; i < n; i++) {
    int l = getid(a[i].l);
    int r = getid(a[i].r);
    sum[l]++;
    sum[r + 1]--;
  }
  for (int i = 1; i <= sz; i++) {
    sum[i] = sum[i - 1] + sum[i];
  }
  for (int i = 1; i < sz; i++) {
    ans[sum[i]] += re[i + 1] - re[i];
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
