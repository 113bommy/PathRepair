#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a >> s;
  bool bol = true;
  int j = 0;
  sort((s).begin(), (s).end());
  reverse((s).begin(), (s).end());
  for (int i = 0; i < s.length(); i++) {
    bol = true;
    for (; j < a.length(); j++) {
      if (s[i] > a[j]) {
        a[j] = s[i];
        bol = false;
        break;
      }
    }
    if (bol) break;
  }
  cout << a << endl;
}
