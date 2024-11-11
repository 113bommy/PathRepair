#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < n; i++) {
    int tt = t[i];
    for (int j = 1; j <= tt; j++) cout << j << " ";
    cout << endl;
  }
  return 0;
}
