#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a >> s;
  sort(s.rbegin(), s.rend());
  int j = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] < s[j]) {
      a[i] = s[j];
      j++;
    }
    if (j == s.size()) break;
  }
  cout << a << endl;
  return 0;
}
