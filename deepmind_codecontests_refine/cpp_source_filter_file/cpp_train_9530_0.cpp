#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, ans = 0;
  string s;
  cin >> n;
  while (n--) {
    cin >> s >> a >> b;
    if (a >= 2400 && b > 2400) ans++;
  }
  if (ans > 0)
    cout << "YES";
  else
    cout << "NO";
}
