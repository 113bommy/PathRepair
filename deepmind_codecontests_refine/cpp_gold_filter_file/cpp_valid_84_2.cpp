#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, s;
  cin >> t;
  for (i = 1; i <= t; i++) {
    cin >> n >> s;
    cout << s / ((n / 2) + 1) << "\n";
  }
}
