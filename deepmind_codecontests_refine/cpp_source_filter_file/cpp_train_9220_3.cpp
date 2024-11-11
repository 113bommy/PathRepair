#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k = 0, c = 0;
  while (n--) {
    string a;
    cin >> a;
    if (a.substr(0, 3) == s)
      c++;
    else
      k++;
  }
  if (c < k)
    cout << "home\n";
  else
    cout << "contest\n";
  return 0;
}
