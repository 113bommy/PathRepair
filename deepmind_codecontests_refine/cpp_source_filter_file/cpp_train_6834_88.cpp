#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  string s;
  cin >> n;
  if (n > 36)
    cout << -1;
  else {
    int z = n / 2;
    while (z--) {
      s += '8';
    }
    if (n & 1) s += '0';
    cout << s;
  }
}
