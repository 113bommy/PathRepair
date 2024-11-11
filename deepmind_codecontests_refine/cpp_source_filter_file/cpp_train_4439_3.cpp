#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  int p = 0;
  int i = 0;
  int cnt = 0;
  while (i < n) {
    if (s[i] == '1' && cnt >= 5)
      p = 1;
    else if (s[i] == '0')
      cnt++;
    i++;
  }
  if (p == 1)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
}
