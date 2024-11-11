#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
inline long long readll() {
  long long res = 0;
  char c = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}
map<long long, long long> f;
map<long long, long long>::iterator it;
int n;
long long a[MAXN];
int main() {
  n = readll();
  for (int i = 1; i <= n; i++) a[i] = readll();
  f[a[1] - 1] = 0;
  for (int i = 1; i < n; i++)
    for (it = f.lower_bound(a[i + 1]); it != f.end(); f.erase(it++)) {
      int x = it->first, y = it->second;
      f[x % a[i + 1]] = max(f[x % a[i + 1]], y + i * (x - x % a[i + 1]));
      f[a[i + 1] - 1] = max(f[a[i + 1] - 1],
                            y + i * ((x + 1) / a[i + 1] * a[i + 1] - a[i + 1]));
    }
  long long ans = 0;
  for (it = f.begin(); it != f.end(); it++)
    ans = max(ans, it->first * n + it->second);
  cout << ans << endl;
  return 0;
}
