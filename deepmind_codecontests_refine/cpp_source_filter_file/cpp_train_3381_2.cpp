#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  if (abs(n - (abs(a) + abs(b)) % 2 == 0 && n >= abs(a) + abs(b)))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
