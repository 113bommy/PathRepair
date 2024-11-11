#include <bits/stdc++.h>
using namespace std;
int mapa[1010];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) mapa[s[i]]++;
  long long int ans = 0;
  for (int i = 0; i <= 500; i++) ans += (long long)mapa[i] * mapa[i];
  printf("%lld\n", ans);
}
