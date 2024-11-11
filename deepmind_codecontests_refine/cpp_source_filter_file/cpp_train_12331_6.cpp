#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3;
  int b1, b2, b3;
  int n;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  cin >> n;
  int ka = 0;
  if ((a1 + a2 + a3) % 5 > 0) {
    ka = 1;
  }
  int kb = 0;
  if ((b1 + b2 + b3) % 10 > 0) {
    kb = 1;
  }
  if ((a1 + a2 + a3) / 5 + ka + (b1 + b2 + b3) / 10 + kb < n) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}
