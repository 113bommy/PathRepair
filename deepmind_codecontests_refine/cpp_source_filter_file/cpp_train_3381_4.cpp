#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, s;
  cin >> a >> b >> s;
  a = labs(a);
  b = labs(b);
  if (s < a + b - 2) {
    cout << "No";
    return 0;
  }
  s -= a + b - 2;
  if (s % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
