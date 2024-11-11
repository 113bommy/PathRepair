#include <bits/stdc++.h>
using namespace std;
long n, ans;
string s;
int main() {
  ans = 0;
  scanf("%ld", &n);
  ;
  scanf("\n");
  getline(cin, s);
  for (long i = 4; i < s.length(); i += n)
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) ans++;
  printf("%ld\n", ans);
  return 0;
}
