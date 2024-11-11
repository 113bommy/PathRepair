#include <bits/stdc++.h>
using namespace std;
int T[18][200001], lg[200001], a[200001];
vector<pair<int, int> > v;
map<int, int> m;
void PreProcess(int n) {
  for (int i = 2; i <= n; ++i) lg[i] = 1 + lg[i / 2];
  for (int i = 1; i <= n; ++i) {
    T[0][i] = a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end(), greater<pair<int, int> >());
  m[1] = n;
  m[n + 1] = n + 1;
  for (int k = 1; k <= lg[n]; ++k)
    for (int i = 1, j = i + (1 << (k - 1)); j <= n; ++i, ++j)
      T[k][i] = (T[k - 1][i] | T[k - 1][j]);
}
int ORQuery(int i, int j) {
  int k = lg[j - i + 1];
  j -= ((1 << k) - 1);
  return (T[k][i] | T[k][j]);
}
int BinarySearchLeft(int x, int y, int val) {
  int l = y, r = y;
  while (x <= y) {
    int mid = (x + y) / 2;
    if (ORQuery(mid, r) == val)
      l = mid, y = mid - 1;
    else
      x = mid + 1;
  }
  return l;
}
int BinarySearchRight(int x, int y, int val) {
  int l = x, r = x;
  while (x <= y) {
    int mid = (x + y) / 2;
    if (ORQuery(l, mid) == val)
      r = mid, x = mid + 1;
    else
      y = mid - 1;
  }
  return r;
}
pair<int, int> GetInterval(int i) {
  auto it = m.lower_bound(i);
  if (it->first != i) --it;
  int l = it->first, r = it->second;
  m.erase(l);
  return make_pair(l, r);
}
void InsertInterval(int l, int r) {
  if (l <= r) m[l] = r;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  PreProcess(n);
  long long ans = 1ll * n * (n + 1) / 2;
  for (auto p : v) {
    int val, i, x, y;
    tie(val, i) = p;
    tie(x, y) = GetInterval(i);
    int l = BinarySearchLeft(x, i, val);
    int r = BinarySearchRight(i, y, val);
    ans -= 1ll * (i - l + 1) * (r - i + 1);
    InsertInterval(x, i - 1);
    InsertInterval(i + 1, y);
  }
  printf("%lld\n", ans);
  return 0;
}
