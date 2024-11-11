#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, pot;
  cin >> a >> b >> pot;
  long long num = 1;
  bool lol = false;
  long long out = pot / b;
  while (num <= b) {
    if (num >= a) {
      cout << num << " ";
      lol = true;
    }
    if (num > out) break;
    num *= pot;
  }
  if (!lol) cout << -1 << endl;
  return 0;
}
