#include <bits/stdc++.h>
using namespace std;
struct nodetmp {
  int left;
  int right;
};
vector<struct nodetmp> v;
int a[1 << 20];
int main() {
  int n;
  cin >> n;
  int left = 0;
  int f = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) {
      if (a[i] > a[i - 1]) {
      } else {
        struct nodetmp tmp;
        tmp.left = left;
        tmp.right = i - 1;
        v.push_back(tmp);
        left = i;
      }
    }
  }
  if (!f) {
    struct nodetmp tmp;
    tmp.left = left;
    tmp.right = n - 1;
    v.push_back(tmp);
  }
  int mx = 0;
  for (int i = 1; i < v.size(); i++) {
    int sz = v[i].right - v[i].left + 1;
    if (sz > 1) {
      int ans = v[i - 1].right - v[i - 1].left + 1;
      if (a[v[i].left + 1] > a[v[i - 1].right]) {
        ans += v[i].right - v[i].left + 1;
      } else {
        ++ans;
      }
      mx = max(ans, mx);
    } else {
      int ans = v[i - 1].right - v[i - 1].left + 1;
      ++ans;
      mx = max(ans, mx);
    }
    sz = v[i - 1].right - v[i - 1].left + 1;
    if (sz > 1) {
      int ans = v[i].right - v[i].left + 1;
      if (a[v[i].left] > a[v[i - 1].right - 1]) {
        ans += v[i - 1].right - v[i - 1].left + 1;
      } else {
        ++ans;
      }
      mx = max(ans, mx);
    } else {
      int ans = v[i].right - v[i].left + 1;
      ++ans;
      mx = max(ans, mx);
    }
  }
  if (v.size() == 1) {
    cout << v[0].right - v[0].left + 1 << endl;
  } else {
    cout << mx << endl;
  }
  return 0;
}
