#include <bits/stdc++.h>
const long long MAX_N = 2e5 + 10;
const long long MOD = 1e9 + 7;
using namespace std;
map<char, int> mp;
set<int> ps[3];
int a[MAX_N];
int fen[MAX_N][3];
int n, q;
void add(int x, int l, int d) {
  for (; x <= n; x += (x & -x)) fen[x][l] += d;
}
int ask(int x, int l) {
  int ans = 0;
  for (; x; x &= x - 1) ans += fen[x][l];
  return ans;
}
void change(int p, int x) {
  add(p, a[p], -1);
  ps[a[p]].erase(p);
  add(p, x, 1);
  ps[x].insert(x);
  a[p] = x;
}
int calc() {
  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    if (ask(n, i) == n) return n;
    int p = (i + 1) % 3;
    if (!ps[p].size()) continue;
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (ask(mid, i) == mid)
        l = mid;
      else
        r = mid;
    }
    ans += l;
    int c = ask(n, i);
    l = 0;
    r = n + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (c - ask(mid - 1, i) == n - mid + 1)
        r = mid;
      else
        l = mid;
    }
    ans += n + 1 - r;
    ans += ask(*ps[p].rbegin(), i) - ask(*ps[p].begin(), i);
  }
  return ans;
}
int main() {
  mp['R'] = 0;
  mp['S'] = 1;
  mp['P'] = 2;
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 1; i <= n; ++i) {
    a[i] = mp[s[i - 1]];
    add(i, a[i], 1);
    ps[a[i]].insert(i);
  }
  printf("%d\n", calc());
  while (q--) {
    int x;
    char c;
    cin >> x >> c;
    int t = mp[c];
    change(x, t);
    printf("%d\n", calc());
  }
  return 0;
}
