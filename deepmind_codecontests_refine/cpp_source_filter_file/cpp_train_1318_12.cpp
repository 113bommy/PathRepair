#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
signed long long int gcd(signed long long int a, signed long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  signed long long int n = s.length();
  signed long long int link = 0, pearl = 0;
  for (signed long long int i = 0; i < n; i++) {
    if (s[i] == '-')
      link++;
    else
      pearl++;
  }
  if (pearl == 1 || link == 0)
    cout << "YES"
         << "\n";
  else if (pearl == 0)
    cout << "NO"
         << "\n";
  else if (link % pearl == 0)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
  return 0;
}
