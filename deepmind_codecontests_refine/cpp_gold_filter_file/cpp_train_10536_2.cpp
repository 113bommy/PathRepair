#include <bits/stdc++.h>
using namespace std;
bool testcase = 1;
void solve() {
  string s;
  cin >> s;
  long long l = 0, r = 0, d = 0, u = 0;
  for (long long i = 0; s[i] != '\0'; i++) {
    char t = s[i];
    if (t == 'L')
      l++;
    else if (t == 'R')
      r++;
    else if (t == 'U')
      u++;
    else if (t == 'D')
      d++;
  }
  long long min1 = min(r, l);
  long long min2 = min(u, d);
  if (min1 == 0 and min2 > 1)
    min2 = 1;
  else if (min2 == 0 and min1 > 1)
    min1 = 1;
  string str = "";
  for (long long i = 0; i < min1; i++) str += 'R';
  for (long long i = 0; i < min2; i++) str += 'D';
  for (long long i = 0; i < min1; i++) str += 'L';
  for (long long i = 0; i < min2; i++) str += 'U';
  long long strl = str.length();
  cout << strl << endl << str;
}
int32_t main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long k;
  if (testcase) {
    cin >> k;
  } else
    k = 1;
  while (k--) {
    solve();
    cout << endl;
  }
  return 0;
}
