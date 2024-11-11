#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int cnt[MAXN];
int n;
struct node {
  int num;
  int cntt;
  node();
  node(int a, int b) : num(a), cntt(b) {}
};
bool cmp(node a, node b) { return a.cntt > b.cntt; }
int check(int mid) {
  int test[MAXN] = {0};
  mid++;
  vector<node> v;
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      v.push_back(node(i, cnt[i]));
    }
  }
  sort(v.begin(), v.end(), cmp);
  int cur = 0;
  int i = 0;
  while (i < n && cur < v.size()) {
    test[i] = v[cur].num;
    int tmp = i;
    for (int j = 2; j <= v[cur].cntt; j++) {
      tmp += mid;
      if (tmp >= n) return 0;
      test[tmp] = v[cur].num;
    }
    cur++;
    i++;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    cin >> n;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      cnt[num]++;
    }
    int l = 1, r = MAXN;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (!check(mid))
        r = mid - 1;
      else
        l = mid;
    }
    cout << l << endl;
  }
  return 0;
}
