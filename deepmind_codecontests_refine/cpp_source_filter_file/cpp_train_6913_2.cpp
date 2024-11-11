#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n > 0 && k == 0) {
    cout << "No solution" << endl;
    return 0;
  }
  cout << k;
  for (int i = 1; i < n; i++) cout << 0;
  cout << endl;
  return 0;
}
