#include <bits/stdc++.h>
using namespace std;
long long n, k, ai[30005], ans;
inline void in(long long &now) {
  char Cget = getchar();
  now = 0;
  while (Cget > '9' || Cget < '0') Cget = getchar();
  while (Cget >= '0' && Cget <= '9') {
    now = now * 10 + Cget - '0';
    Cget = getchar();
  }
}
int main() {
  in(n), in(k);
  for (int i = 1; i <= n; i++) in(ai[i]);
  sort(ai + 1, ai + n + 1);
  for (int i = 1; i <= n; i++) {
    while (ai[i] > k * 2) k <<= 1, ans++;
    k = max(k, ai[i]);
  }
  cout << ans;
  return 0;
}
