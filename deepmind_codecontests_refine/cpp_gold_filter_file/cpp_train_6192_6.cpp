#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do x = x * 10 + ch - '0', ch = getchar();
  while (ch <= '9' && ch >= '0');
  x *= f;
}
struct node {
  int a, b;
  bool operator<(const node &x) const { return b > x.b; }
};
int l[400], c[400];
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n;
  read(n);
  for (int i = 1; i <= n; i++) read(l[i]);
  for (int i = 1; i <= n; i++) read(c[i]);
  unordered_map<int, int> mp, d;
  for (int i = 1; i <= n; i++) {
    if (mp.find(l[i]) == mp.end())
      mp[l[i]] = c[i];
    else
      mp[l[i]] = min(mp[l[i]], c[i]);
  }
  priority_queue<node> pq;
  d[0] = 0;
  pq.push({0, 0});
  int m = 10000;
  while (m--) {
    auto tmp = pq.top();
    pq.pop();
    int x = tmp.a, y = tmp.b;
    if (x == 1) break;
    if (d[x] < y) continue;
    for (auto &i : mp) {
      int a = gcd(i.first, x);
      int b = tmp.b + i.second;
      if (d.find(a) == d.end() || d[a] > b) {
        d[a] = b;
        pq.push({a, b});
      }
    }
  }
  if (d.find(1) != d.end())
    cout << d[1] << endl;
  else
    cout << (-1) << endl;
}
