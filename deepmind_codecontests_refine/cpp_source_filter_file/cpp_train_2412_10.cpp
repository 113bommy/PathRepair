#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  if (t % 2 == 0)
    cout << "NO\n";
  else {
    long long y = (t - 3) / 2;
    if (y > 0)
      cout << "1\n" << y;
    else
      cout << "NO\n";
  }
}
