#include <bits/stdc++.h>
using namespace std;
int main() {
  int even = 0, odd = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0)
      even++;
    else
      odd++;
  }
  int minim = min(even, odd);
  int ans = minim;
  odd -= minim;
  ans += odd / 3;
  cout << ans << endl;
  return 0;
}
