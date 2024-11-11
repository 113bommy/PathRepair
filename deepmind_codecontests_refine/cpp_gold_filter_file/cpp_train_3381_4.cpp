#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, s;
  cin >> a >> b >> s;
  a = labs(a);
  b = labs(b);
  if (s < a + b) {
    cout << "No";
    return 0;
  }
  s -= a + b;
  if (s % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
