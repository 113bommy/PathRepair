#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool q = 0;
  cin >> n;
  int x[1000];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    if (x[i] == 1) q = 1;
  }
  if (q == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
