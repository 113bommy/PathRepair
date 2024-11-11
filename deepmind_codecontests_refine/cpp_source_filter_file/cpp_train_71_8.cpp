#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool ba[1000010];
int p[1000010], l[1000010];
inline void read(register int &x) {
  x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
inline long long calc(int num) {
  int pos = 0;
  register long long ans = p[num];
  if (ba[0]) return -1;
  while (pos < n) {
    register int nepos = pos + num;
    if (nepos >= n) return ans;
    if (ba[nepos]) {
      if (l[nepos] == pos)
        return -1;
      else
        nepos = l[nepos];
    }
    pos = nepos;
    ans += (long long)p[num];
  }
  return ans;
}
int main() {
  read(n), read(m), read(k);
  for (register int i = 1; i <= m; i++) {
    register int pos;
    read(pos);
    ba[pos] = 1;
  }
  for (register int i = 1; i <= k; i++) read(p[i]);
  for (register int i = 1; i <= n; i++) {
    if (ba[i])
      l[i] = l[i - 1];
    else
      l[i] = i;
  }
  long long ans = 999999999999LL;
  for (register int i = 1; i <= k; i++) {
    long long tmp = calc(i);
    if (tmp != -1) ans = min(ans, tmp);
  }
  if (ans == 999999999999)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
