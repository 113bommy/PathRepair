#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
int n, x, y;
int ask(vector<int> v) {
  if (v.size() == 0) return 0;
  printf("? %d", v.size());
  for (int x : v) {
    printf(" %d", x);
  }
  puts("");
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}
int pos1, pos2;
void solve(vector<int> v) {
  int l = 0, r = v.size() - 1, ans = -1;
  while (l <= r) {
    int mid = l + r >> 1;
    vector<int> a;
    for (int i = 0; i <= mid; i++) a.push_back(v[i]);
    int temp = ask(a);
    if (temp == (x ^ y) || temp == y) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  pos1 = v[ans];
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  int diff = 0, spe_bit = 0;
  for (int i = 0; i <= 9; i++) {
    vector<int> v;
    for (int j = 1; j <= n; j++) {
      if (j >> i & 1) v.push_back(j);
    }
    int temp = ask(v);
    if (temp == (x ^ y) || temp == y) {
      diff ^= (1 << i), spe_bit = i;
    }
  }
  vector<int> a, b;
  for (int i = 1; i <= n; i++) {
    if (i >> spe_bit & 1)
      a.push_back(i);
    else
      b.push_back(i);
  }
  if (a.size() > b.size())
    solve(b);
  else
    solve(a);
  pos2 = pos1 ^ diff;
  if (pos2 < pos1) swap(pos1, pos2);
  printf("! %d %d\n", pos1, pos2);
  fflush(stdout);
  return 0;
}
