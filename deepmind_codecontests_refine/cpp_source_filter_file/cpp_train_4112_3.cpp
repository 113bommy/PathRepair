#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, c, d = 0;
  cin >> a;
  int po = 1;
  c = 0;
  for (int i = 1;; i++) {
    b = pow(10, i) - 1;
    if (a > b) {
      c += (b - d) * i;
      d = b;
    } else {
      c += (a - d) * i;
      break;
    }
  }
  if (b + 1 == a) c++;
  cout << c;
}
