#include <bits/stdc++.h>
using namespace std;
string s;
int con(string a) {
  if (a.size() > 6 || (a[0] == '0' && a.size() != 1)) return -1;
  int n = 0;
  int i;
  for (i = 0; i < a.size(); i++) {
    n *= 10;
    n += (a[i] - '0');
  }
  return (n > 1000000 ? -1 : n);
}
int main() {
  int i, j;
  cin >> s;
  int maxi = -1;
  int n = s.size();
  for (i = 1; i < s.size(); i++) {
    for (j = i + 1; j < s.size(); j++) {
      int a = con(s.substr(0, i)), b = con(s.substr(i, j - i)),
          c = con(s.substr(j, n - j + 1));
      if (a == -1 || b == -1 || c == -1) continue;
      maxi = max(maxi, a + b + c);
    }
  }
  cout << maxi << endl;
}
