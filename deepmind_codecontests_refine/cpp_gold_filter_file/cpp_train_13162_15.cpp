#include <bits/stdc++.h>
using namespace std;
long long ans, maxx, s, n, a;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> a;
    ans += a;
    if (a > maxx) maxx = a;
  }
  if (ans - maxx <= s)
    cout << "YES";
  else
    cout << "NO";
}
