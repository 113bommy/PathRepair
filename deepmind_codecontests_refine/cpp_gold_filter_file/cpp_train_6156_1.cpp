#include <bits/stdc++.h>
using namespace std;
const long long R = 998244353;
int n;
char ch[200002];
int main() {
  cin >> n >> ch;
  int p = 0;
  while (p < n && ch[p] == ch[p + 1]) p++;
  long long pref = 1ll * (p + 1);
  p = n - 1;
  while (p && ch[p] == ch[p - 1]) p--;
  long long suff = 1ll * (n - p);
  if (ch[0] == ch[n - 1])
    printf("%d", (suff + pref + suff * pref + 1) % R);
  else
    printf("%d", (suff + pref + 1) % R);
}
