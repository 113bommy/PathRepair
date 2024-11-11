#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:367721060")
using namespace std;
const long long modulus = 1e9 + 7;
const long long INF = 1e18;
const long long MAX = 101000;
int n;
long long s;
long long l;
long long a[MAX];
long long dp[MAX];
struct node {
  long long keyMIN;
  long long keyMAX;
  int tl;
  int tr;
  node *left;
  node *right;
  node(long long *a, int l, int r) : tl(l), tr(r) {
    int mid = (l + r) / 2;
    if (l == r) {
      keyMIN = keyMAX = a[l];
      return;
    } else {
      left = new node(a, l, mid);
      right = new node(a, mid + 1, r);
      keyMIN = min(left->keyMIN, right->keyMIN);
      keyMAX = max(left->keyMAX, right->keyMAX);
    }
  }
};
pair<long long, long long> Query(node *v, int l, int r) {
  int mid = (v->tl + v->tr) / 2;
  if (v->tl == l && v->tr == r) {
    return make_pair(v->keyMIN, v->keyMAX);
  }
  if (mid >= r)
    return Query(v->left, l, r);
  else if (mid < l)
    return Query(v->right, l, r);
  else {
    pair<long long, long long> tmp1 = Query(v->left, l, mid);
    pair<long long, long long> tmp2 = Query(v->right, mid + 1, r);
    return make_pair(min(tmp1.first, tmp2.first),
                     max(tmp1.second, tmp2.second));
  }
}
void update(node *v, int pos, int x) {
  int mid = (v->tl + v->tr) / 2;
  if (v->tl == pos && v->tr == pos) {
    v->keyMIN = v->keyMAX = x;
    return;
  }
  if (pos <= mid)
    update(v->left, pos, x);
  else if (pos > mid)
    update(v->right, pos, x);
  v->keyMIN = min(v->left->keyMIN, v->right->keyMIN);
  v->keyMAX = max(v->left->keyMAX, v->right->keyMAX);
}
int main() {
  long long MIN = 1e9 + 7, MAX = -1e9 + 7;
  cin >> n >> s >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < MIN) MIN = a[i];
    if (a[i] > MAX) MAX = a[i];
  }
  if (n < l) {
    cout << -1 << endl;
    return 0;
  }
  if (MAX - MIN < s) {
    cout << 1 << endl;
    return 0;
  }
  node *rootMAS = new node(a, 1, n);
  node *rootDP = new node(dp, 1, n);
  for (int i = n; i >= n - l + 2; i--) {
    update(rootDP, i, 1e9 + 300);
  }
  for (int i = n - l + 1; i >= 1; i--) {
    long long good = i;
    long long bad = n + 1;
    while (bad - good > 1) {
      long long mid = (good + bad) / 2;
      pair<long long, long long> tmp = Query(rootMAS, i, mid);
      if (tmp.second - tmp.first <= s)
        good = mid;
      else
        bad = mid;
    }
    if (good - i + 1 < l) {
      update(rootDP, i, 1e9 + 300);
    } else if (good == n) {
      update(rootDP, i, 1);
    } else {
      pair<long long, long long> tmp = Query(rootDP, i + l, good + 1);
      update(rootDP, i, tmp.first + 1);
    }
  }
  pair<long long, long long> tmp = Query(rootDP, 1, 1);
  if (tmp.first > n) {
    cout << -1 << endl;
    return 0;
  } else {
    cout << tmp.first << endl;
  }
  return 0;
}
