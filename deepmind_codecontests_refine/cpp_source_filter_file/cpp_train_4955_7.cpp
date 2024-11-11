#include <bits/stdc++.h>
using namespace std;
string a, b, s;
int i;
int main() {
  cin >> a >> b;
  for (i = 0; i < a.length(); i++) {
    if (a[i] < b[i]) return cout << -1, 0;
    if (a[i] == b[i]) s += char(a[i] + 1);
    if (a[i] > b[i]) s += char(b[i]);
  }
  cout << s;
}
