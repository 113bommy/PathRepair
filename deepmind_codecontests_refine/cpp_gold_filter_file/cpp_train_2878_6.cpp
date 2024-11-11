#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9 + 123;
long long eps = 1e-6;
struct item {
  int left, right;
  long long c, st;
  item *l, *r;
  item() {}
  item(int left, int right)
      : c(0), left(left), right(right), l(nullptr), r(nullptr), st(0) {}
};
typedef item *pitem;
void push(pitem &v) {
  if (v->l) v->l->c += v->st, v->l->st += v->st;
  if (v->r) v->r->c += v->st, v->r->st += v->st;
  v->st = 0;
}
void build(pitem &v, int left, int right) {
  v = new item(left, right);
  if (left == right) return;
  int mid = (left + right) / 2;
  build(v->l, left, mid);
  build(v->r, mid + 1, right);
}
void inc(pitem &v, int left) {
  if (v->left == left) {
    v->c++, v->st++;
    return;
  }
  if (left <= v->l->right) {
    v->r->c++, v->r->st++;
    inc(v->l, left);
  } else
    inc(v->r, left);
}
long long get(pitem &v, int x) {
  if (x == v->left) return v->c;
  push(v);
  if (v->l->right >= x)
    return get(v->l, x);
  else
    return get(v->r, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, w;
  cin >> n >> w;
  vector<pair<int, int> > a(n);
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<pair<double, int> > t1(n), t2(n);
  for (i = 0; i < n; i++)
    t1[i] = {abs(a[i].first) / (double)(abs(a[i].second + w)), i};
  vector<int> num(n);
  sort(t1.begin(), t1.end());
  int j = 0;
  long long last = 0;
  long long ans = 0;
  for (i = 0; i < n; i++) {
    if (i == 0)
      num[t1[i].second] = 0;
    else {
      if (t1[i].first != t1[i - 1].first)
        ans += (((long long)i - last) * ((long long)i - last - 1)) / 2, j++,
            last = i;
      num[t1[i].second] = j;
    }
  }
  ans += (((long long)n - last) * ((long long)n - 1 - last)) / 2;
  if (w == 0) {
    cout << ans;
    return 0;
  }
  for (i = 0; i < n; i++)
    t2[i] = {abs(a[i].first) / (double)(abs(a[i].second - w)), num[i]};
  sort(t2.begin(), t2.end());
  pitem s = nullptr;
  build(s, 0, n);
  stack<int> ord;
  for (i = n - 1; i >= 0; i--) {
    ans += get(s, t2[i].second);
    ord.push(t2[i].second);
    if (i == 0 || t2[i].first != t2[i - 1].first) {
      ans += ((long long)(ord.size()) * ((long long)ord.size() - 1)) / 2;
      while (!ord.empty()) {
        inc(s, ord.top() + 1);
        ord.pop();
      }
    }
  }
  vector<pair<double, int> > t3(n);
  for (i = 0; i < n; i++)
    t3[i].first =
        a[i].first / (abs(a[i].first)) * fabs(a[i].first / (double)a[i].second);
  sort(t3.begin(), t3.end());
  cout << ans;
}
