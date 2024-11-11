#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n;
  int a = 0;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (a == 1 && t == 0) {
      cout << "NO";
      return 0;
    }
    if (t % 2 == 1) a ^= 1;
  }
  if (a)
    cout << "NO";
  else
    cout << "YES";
}
