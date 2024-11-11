#include <bits/stdc++.h>
using namespace std;
int n;
struct dd {
  int gt;
  int x;
  int v;
};
vector<dd> a;
struct Data {
  long long sum;
  int sl;
};
Data it[200009 * 8];
Data ans;
long long res;
void update(int i, int l, int r, int pos, int data) {
  if (l > pos || r < pos) return;
  if (l == r) {
    it[i].sum = data;
    it[i].sl = 1;
    return;
  }
  int mid = (l + r) / 2;
  update(i * 2, l, mid, pos, data);
  update(i * 2 + 1, mid + 1, r, pos, data);
  it[i].sum = it[i * 2].sum + it[i * 2 + 1].sum;
  it[i].sl = it[i * 2].sl + it[i * 2 + 1].sl;
}
void find(int i, int l, int r, int u, int v) {
  if (l > r) return;
  if (r < u || l > v) return;
  if (u <= l && r <= v) {
    ans.sum = ans.sum + it[i].sum;
    ans.sl = ans.sl + it[i].sl;
    return;
  }
  int mid = (l + r) / 2;
  find(i * 2, l, mid, u, v);
  find(i * 2 + 1, mid + 1, r, u, v);
}
bool cmp(const dd& a, const dd& b) {
  if (a.v == b.v) {
    return a.x < b.x;
  }
  return a.v < b.v;
}
bool cmp1(const dd& a, const dd& b) { return a.x < b.x; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    dd tmp;
    cin >> tmp.x;
    a.push_back(tmp);
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].v;
  }
  sort(a.begin(), a.end(), cmp1);
  for (int i = 0; i < n; i++) {
    a[i].gt = i + 1;
  }
  sort(a.begin(), a.end(), cmp);
  update(1, 1, n, a[n - 1].gt, a[n - 1].x);
  for (int i = n - 2; i >= 0; i--) {
    long long tmp = a[i].x;
    ans.sl = 0;
    ans.sum = 0;
    find(1, 1, n, a[i].gt + 1, n);
    res = res + ans.sum - (tmp * ans.sl);
    update(1, 1, n, a[i].gt, a[i].x);
  }
  cout << res << endl;
}
