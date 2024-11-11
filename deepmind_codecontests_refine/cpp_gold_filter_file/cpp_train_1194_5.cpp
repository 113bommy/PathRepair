#include <bits/stdc++.h>
using namespace std;
const long long MOOD = 1000 * 1000 * 1000 + 7;
int main() {
  int n, a1 = 0, a2 = 0, a3 = 0, a4 = 0, mac = 0;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') a1++;
    if (s[i] == 'G') a2++;
    if (s[i] == 'C') a3++;
    if (s[i] == 'T') a4++;
    mac = max(a1, a2);
    mac = max(mac, a3);
    mac = max(mac, a4);
  }
  int l = 0;
  if (a1 == mac) l++;
  if (a2 == mac) l++;
  if (a3 == mac) l++;
  if (a4 == mac) l++;
  long long res = 1;
  for (int i = 0; i < n; i++) {
    res *= l;
    res %= MOOD;
  }
  cout << res << endl;
  return 0;
}
