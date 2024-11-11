#include <bits/stdc++.h>
using namespace std;
int t[1000010], a;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a;
    t[a] = 1;
  }
  for (int i = 1; i <= n - 1; i++) {
    if (t[i] == 0) cout << i;
  }
  return 0;
}
