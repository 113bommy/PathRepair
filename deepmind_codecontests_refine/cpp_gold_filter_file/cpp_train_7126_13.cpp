#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
map<int, int> mp;
int n, a, b, f[maxn], vs[maxn], sta[maxn], p[maxn];
int gf(int x) { return f[x] == x ? x : f[x] = gf(f[x]); }
int main() {
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &p[i]), mp[p[i]] = i;
    f[i] = i;
  }
  for (int i = 1; i < n + 1; i++) {
    if (mp.count(a - p[i])) f[gf(mp[a - p[i]])] = gf(i), vs[i] |= 1;
    if (mp.count(b - p[i])) f[gf(mp[b - p[i]])] = gf(i), vs[i] |= 2;
  }
  for (int i = 1; i < n + 1; i++) sta[i] = 3;
  for (int i = 1; i < n + 1; i++) sta[gf(i)] &= vs[i];
  for (int i = 1; i < n + 1; i++)
    if (sta[i] == 0) {
      cout << "NO";
      return 0;
    }
  cout << "YES" << endl;
  for (int i = 1; i < n + 1; i++) {
    int st = sta[gf(i)];
    cout << 0 + ((st & 1) == 0);
    cout << " ";
  }
  return 0;
}
