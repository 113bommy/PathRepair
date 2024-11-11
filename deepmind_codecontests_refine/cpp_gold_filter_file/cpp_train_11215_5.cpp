#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, min = 10000000, k = 0;
  cin >> a;
  int m[10];
  for (int i = 0; i < a; i++) cin >> m[i];
  if (a == 1) {
    cout << -1;
    return 0;
  }
  if ((a == 2) && (m[0] == m[1])) {
    cout << -1;
    return 0;
  }
  cout << 1 << endl;
  for (int i = 0; i < a; i++)
    if (m[i] < min) min = m[i];
  for (int i = 0; i < a; i++)
    if ((m[i] == min) && (k == 0)) {
      cout << i + 1;
      k = 1;
    }
  return 0;
}
