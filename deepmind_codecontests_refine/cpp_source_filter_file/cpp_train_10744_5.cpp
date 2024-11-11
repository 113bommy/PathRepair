#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int re = a[2] - a[1] - a[0];
    if (re <= 2)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
}
