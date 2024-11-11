#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct node {
  int x, gas;
  node() {}
  node(int _x, int _gas) : x(_x), gas(_gas) {}
};
bool operator<(const node a, const node b) { return a.x < b.x; }
bool cmp(node a, node b) { return a.x < b.x; }
struct tree {
  vector<int> a;
  int n;
  tree(vector<int> *arr) {
    for (n = 1; n < (int)arr->size(); n <<= 1)
      ;
    a.resize(n << 1);
    for (int k = 0; k < (int)arr->size(); k++) {
      a[k + n] = (*arr)[k];
    }
    for (int k = arr->size(); k < n; k++) {
      a[k + n] = INF;
    }
    for (int k = n - 1; k >= 0; k--) {
      a[k] = min(a[k << 1], a[(k << 1) | 1]);
    }
  }
  int query(int v, int L, int R, int l, int r) {
    if (l > r) {
      return INF;
    }
    if (l == L && R == r) {
      return a[v];
    }
    int mid = (L + R) / 2;
    return min(query(v << 1, L, mid, l, min(mid, r)),
               query((v << 1) | 1, mid + 1, R, max(l, mid + 1), r));
  }
  int call_query(int l, int r) { return query(1, 0, n - 1, l, r); }
};
int main() {
  int d, n, m;
  cin >> d >> n >> m;
  vector<node> arr(m);
  for (int k = 0; k < m; k++) {
    cin >> arr[k].x >> arr[k].gas;
  }
  arr.push_back(node(0, 0));
  arr.push_back(node(d, 0));
  sort(arr.begin(), arr.end(), cmp);
  vector<int> help(arr.size());
  for (int k = 0; k < (int)arr.size(); k++) {
    help[k] = arr[k].gas;
  }
  tree t(&help);
  long long cur = n, res = 0;
  for (int k = 1; k < (int)arr.size() - 1; k++) {
    int low = k + 1, high = arr.size() - 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (t.call_query(k + 1, mid) < arr[k].gas) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    int ind = -1;
    if (t.call_query(k + 1, high) < arr[k].gas) {
      ind = high;
    }
    if (t.call_query(k + 1, low) < arr[k].gas) {
      ind = low;
    }
    cur -= arr[k].x - arr[k - 1].x;
    int len = arr[ind].x - arr[k].x;
    if (len > cur && len <= n) {
      res += (len - cur) * arr[k].gas;
      cur = len;
    }
    if (len > n) {
      res += (n - cur) * arr[k].gas;
      cur = n;
    }
    if (arr[k].x - arr[k - 1].x > n) {
      cout << -1;
      return 0;
    }
  }
  if (arr[arr.size() - 1].x - arr[arr.size() - 2].x > n) {
    cout << -1;
    return 0;
  }
  cout << res;
  return 0;
}
