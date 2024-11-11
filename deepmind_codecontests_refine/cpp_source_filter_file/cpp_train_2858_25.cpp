#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
  string s[] = {"January",   "February", "March",    "April",
                "May",       "June",     "July",     "August",
                "September", "October",  "November", "December"};
  for (int i = 0; i <= 11; i++) mp[s[i]] = i;
  string ans;
  char c[30];
  scanf("%s", &c);
  ans = c;
  int n;
  scanf("%d", &n);
  int x = mp[ans];
  x += n;
  if (x <= 12)
    cout << s[x];
  else
    cout << s[x % 12];
}
