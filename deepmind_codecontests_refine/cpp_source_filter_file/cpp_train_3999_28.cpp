#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n - 1; i++) {
    if (x[i] == x[i + 1]) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
