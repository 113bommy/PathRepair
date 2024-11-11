#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[200002];
struct node {
  long long val = 0;
  long long l = 0, r = 0;
  node* left = NULL;
  node* right = NULL;
  node(long long x, long long y) {
    l = x;
    r = y;
  }
};
void add(node* cur, long long pos) {
  long long l = cur->l;
  long long r = cur->r;
  if (l == r - 1) {
    cur->val = 1;
    return;
  }
  long long m = (l + r) / 2;
  if (m > pos) {
    if (!cur->left) {
      cur->left = new node(l, m);
    }
    add(cur->left, pos);
  } else {
    if (!cur->right) {
      cur->right = new node(m, r);
    }
    add(cur->right, pos);
  }
  cur->val =
      ((cur->left) ? cur->left->val : 0) + ((cur->right) ? cur->right->val : 0);
}
long long get(node* cur, long long L, long long R) {
  if (!cur) return 0;
  if (cur->l == L && cur->r == R) return cur->val;
  long long m = (cur->l + cur->r) / 2;
  if (m >= R) {
    if (cur->left) {
      return get(cur->left, L, R);
    } else
      return 0;
  } else if (m <= L) {
    if (cur->right) {
      return get(cur->right, L, R);
    } else
      return 0;
  }
  return get(cur->left, L, m) + get(cur->right, m, R);
}
int main(int argc, char const* argv[]) {
  cin >> n;
  int x, y;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    a[i] = make_pair(-y, x);
  }
  sort(a + 1, a + n + 1);
  const int N = 100000003;
  node* root = new node(0, N);
  int j;
  int in = 1;
  long long ans = 0;
  for (int i = 1; i <= n; i = j) {
    vector<int> v;
    j = i;
    while (j <= n && a[i].first == a[j].first) {
      v.push_back(a[j].second);
      j++;
    }
    sort(v.begin(), v.end());
    v.push_back(N);
    for (int u = 0; u + 1 < v.size(); u++) {
      long long x = get(root, 0, v[u]);
      long long y = get(root, v[u] + 1, v[u + 1]);
      ans += (x + 1) * (y + 1);
      add(root, v[u]);
    }
  }
  cout << ans << endl;
  return 0;
}
