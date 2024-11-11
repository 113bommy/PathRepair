#include <bits/stdc++.h>
using namespace std;
int ans;
string a, b;
int main() {
  cin >> a >> b;
  for (int i = 0; i + b.length() <= a.length(); ++i) {
    if (a.substr(i, b.length()) == b) {
      ++ans;
      a[i + b.length() - 1] = '#';
    }
  }
  cout << ans << endl;
  return 0;
}
