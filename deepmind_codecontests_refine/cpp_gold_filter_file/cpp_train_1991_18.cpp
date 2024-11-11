#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 4;
char s[N];
int BIT[N][3];
void upd(int idx, int n, int val, int col) {
  while (idx <= n) {
    BIT[idx][col] += val;
    idx += idx & (-idx);
  }
}
int Query(int idx, int col) {
  int sum = 0;
  while (idx > 0) {
    sum += BIT[idx][col];
    idx -= idx & (-idx);
  }
  return sum;
}
int SUM(int i, int j, int col) { return Query(j, col) - Query(i - 1, col); }
int n, q;
set<int> S[3];
int query(int col1, int col2) {
  int other = 3 - (col1 + col2);
  if (S[other].size() == 0) {
    return SUM(1, n, col1);
  }
  if (S[col2].size() == 0) {
    return 0;
  }
  auto it = S[col2].begin();
  int fr = *it;
  it = S[col2].end();
  it--;
  int la = *it;
  int ans = SUM(fr, la, col1);
  it = S[other].begin();
  int l = *it;
  l = min(l, fr);
  ans += SUM(1, l, col1);
  it = S[other].end();
  it--;
  int r = *it;
  r = max(r, la);
  ans += SUM(r, n, col1);
  return ans;
}
int f(char ch) {
  if (ch == 'R') return 0;
  if (ch == 'S') return 1;
  return 2;
}
int query() { return query(0, 1) + query(2, 0) + query(1, 2); }
int main() {
  cin >> n >> q;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'R') {
      S[0].insert(i);
      upd(i, n, +1, 0);
    } else if (s[i] == 'S') {
      S[1].insert(i);
      upd(i, n, +1, 1);
    } else {
      S[2].insert(i);
      upd(i, n, +1, 2);
    }
  }
  printf("%d\n", query());
  for (int i = 1; i <= q; i++) {
    char t[3];
    int idx;
    scanf("%d %s", &idx, t);
    int col1 = f(s[idx]);
    S[col1].erase(idx);
    upd(idx, n, -1, col1);
    s[idx] = t[0];
    col1 = f(s[idx]);
    S[col1].insert(idx);
    upd(idx, n, +1, col1);
    printf("%d\n", query());
  }
  return 0;
}
