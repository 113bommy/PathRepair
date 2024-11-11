#include <bits/stdc++.h>
using namespace std;
int cnt;
int main() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (b - a > 0) cnt++;
  }
  cout << cnt;
  return 0;
}
