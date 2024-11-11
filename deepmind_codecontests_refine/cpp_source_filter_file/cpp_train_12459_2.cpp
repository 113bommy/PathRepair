#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
int Set(int N, int pos) { return N = N | (1 << pos); }
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int hr[] = {-2, -2, -1, +1, +2, +2, -1, +1};
int hc[] = {+1, -1, +2, +2, -1, +1, -2, -2};
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
const int MAXN = (int)1e5 + 9;
string s1, s2;
bool f(int i) {
  if (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '0') return true;
  if (s1[i] == '0' && s1[i + 1] == '0' && s2[i + 1] == '0') return true;
  if (s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') return true;
  if (s1[i] == '0' && s2[i + 1] == '0' && s2[i] == '0') return true;
  return false;
}
int main() {
  int i, j, k, l, m, n, p, q, x, y, u, v, r, tc, t;
  cin >> s1 >> s2;
  l = s1.size();
  int ans = 0;
  for (i = 0; i + 1 < l; i++) {
    if (s1[i] == '0' && s1[i + 1] == '0' && s1[i + 2] == '0' && s2[i] == '0' &&
        s2[i + 1] == '0' && s2[i + 2] == '0') {
      ans += 2, i += 3;
      continue;
    }
    if (f(i)) {
      i += 2;
      ans++;
    } else
      i++;
  }
  cout << ans << endl;
  return 0;
}
