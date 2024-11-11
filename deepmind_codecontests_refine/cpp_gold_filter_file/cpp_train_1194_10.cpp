#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9) + 7;
int Pow(int a, int b, int c) {
  int res = 1;
  while (b) {
    if (b & 1) res = int((res * 1ll * a) % c);
    a = int((a * 1ll * a) % c);
    b >>= 1;
  }
  return res;
}
int main() {
  string s;
  int cnt = 0, u[26] = {0}, n;
  scanf("%d\n", &n);
  cin >> s;
  for (int(i) = 0; (i) < int((s).size()); ++(i)) u[s[i] - 'A']++;
  sort(u, u + 26);
  int mx = u[25];
  for (int(i) = 0; (i) < (26); ++(i))
    if (u[i] == mx) cnt++;
  printf("%d\n", Pow(cnt, n, mod));
  return 0;
}
