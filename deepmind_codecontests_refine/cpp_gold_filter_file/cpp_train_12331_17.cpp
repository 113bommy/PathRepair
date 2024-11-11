#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int a1, a2, a3, b1, b2, b3, n, total = 0;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  if ((a1 + a2 + a3) % 5 == 0) {
    total = total + (a1 + a2 + a3) / 5;
  } else {
    total = total + 1 + (a1 + a2 + a3) / 5;
  }
  if ((b1 + b2 + b3) % 10 == 0) {
    total = total + (b1 + b2 + b3) / 10;
  } else {
    total = total + 1 + (b1 + b2 + b3) / 10;
  }
  if (total <= n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
