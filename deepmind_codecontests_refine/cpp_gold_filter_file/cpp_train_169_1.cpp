#include <bits/stdc++.h>
using namespace std;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
int arr[100010];
int tree[100010 * 4];
void init(int node, int b, int e) {
  if (b == e) {
    tree[node] = arr[e];
    return;
  }
  int lft = node * 2;
  int rgt = lft + 1;
  int mid = (b + e) / 2;
  init(lft, b, mid);
  init(rgt, mid + 1, e);
  tree[node] = min(tree[lft], tree[rgt]);
}
int q(int node, int b, int e, int l, int r) {
  if (l > e | r < b) {
    return 100010;
  }
  if (b >= l && e <= r) {
    return tree[node];
  }
  int lft = node * 2;
  int rgt = lft + 1;
  int mid = (b + e) / 2;
  int x = q(lft, b, mid, l, r);
  int y = q(rgt, mid + 1, e, l, r);
  return min(x, y);
}
int main() {
  long long n;
  cin >> n;
  string a;
  cin >> a;
  vector<string> v;
  v.clear();
  for (int i = 0; i < n - 1; i++) {
    string tmp = "";
    tmp += a[i];
    tmp += a[i + 1];
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  int c = 0;
  int maxc = 0;
  string ans = v[0];
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == v[i + 1]) {
      c++;
      if (c > maxc) {
        maxc = c;
        ans = v[i];
      }
    } else
      c = 0;
  }
  cout << ans << endl;
  return 0;
}
