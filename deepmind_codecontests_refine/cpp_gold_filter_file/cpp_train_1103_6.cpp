#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string s, s2;
  cin >> s;
  long long c = 0;
  s2 = s;
  sort(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    c += s[i] - 48;
  }
  if (c >= k)
    cout << "0";
  else {
    long long t = 0, tt = 0;
    k = k - c;
    for (int i = 0; i < s.length(); i++) {
      if (tt >= k)
        break;
      else {
        tt += 9 - (s[i] - 48);
        t++;
      }
    }
    cout << t;
  }
}
