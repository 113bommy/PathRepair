#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int num_l = 0, num_p = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '-')
      num_l++;
    else
      num_p++;
  }
  if (num_p == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (num_p == 1) {
    cout << "YES" << endl;
    return 0;
  }
  if (num_l % num_p == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
