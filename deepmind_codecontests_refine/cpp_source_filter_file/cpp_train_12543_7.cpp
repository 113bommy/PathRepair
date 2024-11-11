#include <bits/stdc++.h>
using namespace std;
int correct(int num) {
  if (num > 501) return num - 501;
  return num;
}
int main(void) {
  int k;
  cin >> k;
  int n = 1002, m = n * k;
  if ((k % 2) == 0) {
    cout << "NO\n";
    return 0;
  }
  if (k == 1) {
    cout << "YES\n2 1\n1 2";
    return 0;
  }
  cout << "YES\n";
  cout << n << " " << m << "\n";
  for (int i = 1; i < 502; i++) {
    for (int j = 1; j <= k / 2; j++) {
      cout << i << " " << correct(i + j) << "\n";
      cout << 501 + i << " " << correct(i + j) + 501 << "\n";
    }
  }
  cout << 1 << " " << 502 << "\n";
  for (int i = 2; i < 252; i++) {
    cout << i << " " << i + 250 << "\n";
    cout << i + 501 << " " << i + 751;
    if (i < 251) cout << "\n";
  }
  return 0;
}
