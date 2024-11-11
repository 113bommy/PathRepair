#include <bits/stdc++.h>
using namespace std;
int n, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  if (t < 10) {
    for (int i = 0; i < n; i++) cout << t;
  } else {
    if (n < 10)
      cout << -1;
    else {
      cout << 1;
      for (int i = 0; i < n - 1; i++) cout << 0;
    }
  }
  return 0;
}
