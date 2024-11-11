#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string str;
  long long int x, a, b;
  bool res = false;
  cin >> x;
  while (x--) {
    cin >> str >> a >> b;
    if ((a >= 2400) && (b >= 2400) && ((b - a) > 0)) {
      res = true;
    }
  }
  if (res) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
