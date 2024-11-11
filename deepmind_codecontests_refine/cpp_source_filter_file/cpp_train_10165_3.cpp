#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int mod = 1000000007;
const int maxn = 500010;
int arr[maxn];
int tree[4 * maxn];
int gcdcnt = 0;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
void Build(int node, int b, int e) {
  if (b == e) {
    tree[node] = arr[b];
    return;
  }
  int left = node * 2;
  int right = node * 2 + 1;
  int mid = (b + e) / 2;
  Build(left, b, mid);
  Build(right, mid + 1, e);
  tree[node] = gcd(tree[left], tree[right]);
}
void update(int node, int b, int e, int i, int newvalue) {
  if (i < b or i > e) {
    return;
  }
  if (b == e and b == i) {
    tree[node] = arr[i] = newvalue;
    return;
  }
  int left = node * 2;
  int right = node * 2 + 1;
  int mid = (b + e) / 2;
  if (i <= mid)
    update(left, b, mid, i, newvalue);
  else
    update(right, mid + 1, e, i, newvalue);
  tree[node] = gcd(tree[left], tree[right]);
}
void query(int node, int b, int e, int l, int r, int x) {
  if (l > e or r < b or tree[node] % x == 0 or gcdcnt > 1) {
    return;
  }
  if (b == e) {
    if (tree[node] % x != 0) {
      gcdcnt++;
    }
    return;
  }
  int left = node * 2;
  int right = node * 2 + 1;
  int mid = (b + e) / 2;
  query(left, b, mid, l, r, x);
  query(right, mid + 1, e, l, r, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  Build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int cnt = 0;
    int type, l, r, x, i, y;
    cin >> type;
    if (type == 1) {
      cin >> l >> r >> x;
      gcdcnt = 0;
      query(1, 1, n, l, r, x);
      if (gcdcnt > 1)
        cout << "No"
             << "\n";
      else
        cout << "Yes"
             << "\n";
    } else {
      cin >> i >> y;
      update(1, 1, n, i, y);
    }
  }
  return 0;
}
