#include <bits/stdc++.h>
const int N = 100005;
using ll = long long;
using ull = unsigned long long;
using namespace std;
inline void up(int &x, int y) {
  x = x + y < 1000000007 ? x + y : x + y - 1000000007;
}
inline char emm(int q, int w) { return q == w ? '\n' : ' '; }
inline void read(int &a) {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  a = x * f;
}
int lowbit(int q) { return q & (-q); }
int bit[4][200010];
int query(int ss, int q) {
  int sum = 0;
  for (; q; q -= lowbit(q)) sum += bit[ss][q];
  return sum;
}
void update(int ss, int q, int w) {
  for (; q < 200010; q += lowbit(q)) bit[ss][q] += w;
}
map<char, int> mp;
char s[200010];
int len, n, q, a, b;
char c;
set<int> st[4], sst[4];
int cal() {
  int ans = 0;
  for (int i = 1; i <= 3; i++)
    if (!st[i].empty()) {
      int j = i + 1, k = i - 1;
      if (j > 3) j -= 3;
      if (k < 1) k += 3;
      swap(j, k);
      if (st[k].empty())
        ans += query(i, n);
      else if (!st[j].empty()) {
        ans += query(i, -*sst[j].begin()) - query(i, *st[j].begin());
        ans += query(i, n) - query(i, max(-*sst[j].begin(), -*sst[k].begin()));
        ans += query(i, min(*st[j].begin(), *st[k].begin()));
      }
    }
  return ans;
}
int main() {
  mp['R'] = 1;
  mp['P'] = 2;
  mp['S'] = 3;
  scanf("%d%d%s", &n, &q, s + 1);
  len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    int cow = mp[s[i]];
    update(cow, i, 1);
    st[cow].insert(i);
    sst[cow].insert(-i);
  }
  printf("%d\n", cal());
  while (q--) {
    scanf("%d%s", &a, &c);
    int ts = mp[s[a]];
    s[a] = c;
    int gz = mp[s[a]];
    st[ts].erase(a);
    sst[ts].erase(-a);
    st[gz].insert(a);
    sst[gz].insert(-a);
    update(ts, a, -1);
    update(gz, a, 1);
    printf("%d\n", cal());
  }
  return 0;
}
