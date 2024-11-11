#include <bits/stdc++.h>
using namespace std;
int tree[200001];
int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}
void update(int idx, int val) {
  while (idx <= 200000) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}
int main() {
  for (int i = 0; i < 200001; i++) tree[i] = 0;
  int n;
  cin >> n;
  vector<int> p1(n);
  vector<int> p2(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p1[i] = x + read(x);
    update(x + 1, -1);
  }
  for (int i = 0; i < 200001; i++) tree[i] = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    p2[i] = x + read(x);
    update(x + 1, -1);
  }
  vector<int> sm(n);
  int carry = 0;
  int lim = 1;
  for (int i = n - 1; i >= 0; i--) {
    int tot = p1[i] + p2[i] + carry;
    sm[i] = tot % lim;
    carry = tot / lim;
    lim++;
  }
  for (int i = 0; i < 200001; i++) tree[i] = 0;
  for (int i = 1; i <= n; i++) update(i, 1);
  vector<int> p3(n);
  for (int i = 0; i < n; i++) {
    int lo, hi;
    lo = 1;
    hi = n;
    int md;
    while (lo <= hi) {
      md = (lo + hi) / 2;
      if (read(md) < sm[i] + 1) {
        lo = md + 1;
      } else {
        hi = md - 1;
      }
    }
    int x = lo;
    p3[i] = x - 1;
    update(x, -1);
  }
  for (int i = 0; i < n; i++) cout << p3[i] << " ";
  cout << endl;
}
