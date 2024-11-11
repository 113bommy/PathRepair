#include <bits/stdc++.h>
using namespace std;
const int_fast64_t M = 1000000007;
struct snode {
  int_fast64_t data;
  int_fast64_t left, right;
  snode* left_child;
  snode* right_child;
};
int_fast64_t poww(int_fast64_t x, int_fast64_t y, int_fast64_t m) {
  int_fast64_t ans = 1;
  while (y) {
    if (y % 2) {
      ans = (ans * x) % m;
    }
    x = x * x % m;
    y = y / 2;
  }
  return ans;
}
const int32_t maxm = 2000007;
int_fast64_t SOE[maxm];
int_fast64_t fact(int_fast64_t a, int_fast64_t m) {
  int_fast64_t ans = 1;
  while (a > 1) {
    ans *= a;
    ans %= m;
    a--;
  }
  return ans;
}
int_fast64_t nCr(int_fast64_t n, int_fast64_t r, int_fast64_t m) {
  int_fast64_t a = fact(n, M);
  int_fast64_t ans = a;
  int_fast64_t b = fact(n - r, M);
  int_fast64_t c = fact(r, M);
  b = poww(b, m - 2, m);
  c = poww(c, m - 2, m);
  ans = (ans * b) % m;
  ans = (ans * c) % m;
  return ans;
}
snode* make_seg_tree(snode* root, int_fast64_t arr[], int_fast64_t left,
                     int_fast64_t right) {
  snode* temp = new snode;
  temp->left = left;
  temp->right = right;
  temp->left_child = NULL;
  temp->right_child = NULL;
  if (left == right) {
    return temp;
  }
  int_fast64_t l1, r1, l2, r2;
  l1 = left;
  r2 = right;
  r1 = (left + right) / 2;
  l2 = r1 + 1;
  temp->left_child = make_seg_tree(temp, arr, l1, r1);
  temp->right_child = make_seg_tree(temp, arr, l2, r2);
  return temp;
}
bool check(int_fast64_t m) {}
int_fast64_t res;
void binary_search(int_fast64_t len) {
  int_fast64_t l = 1, r = len;
  bool res;
  while (l <= r) {
    int_fast64_t m = (l + r) / 2;
    if (check(m)) {
      res = m;
      l = m + 1;
    } else
      r = m - 1;
  }
  return;
}
int_fast64_t fac[1000003];
int_fast64_t inv[1000003];
int_fast64_t ANS[1000003];
int_fast64_t nCk(int_fast64_t n, int_fast64_t k) {
  int_fast64_t ANS = fac[n];
  ANS *= ((inv[n - k] * inv[k]) % M);
  return ANS % M;
}
void solve() {
  int_fast64_t n, t;
  cin >> n >> t;
  pair<int_fast64_t, int_fast64_t> arr[n];
  for (int_fast64_t i = 0; i < n; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr, arr + n);
  int_fast64_t c = 0;
  for (int_fast64_t i = 0; i < n - 1; i++) {
    if (arr[i].second != arr[i + 1].second + 1) {
      c++;
    }
  }
  if (c <= t) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  };
  return;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int_fast64_t t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
