#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i, cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == 'A')
      cnt1++;
    else if (s[i] == 'F')
      cnt2++;
    else
      cnt3++;
  }
  if (cnt3 == n || cnt2 == n)
    cout << "0" << endl;
  else if (cnt3 == 1)
    cout << "1" << endl;
  else
    cout << cnt1 << endl;
}
