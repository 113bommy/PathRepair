#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a, seat, two = 0;
  string ans = "YES";
  cin >> n >> k;
  seat = n * 8;
  for (int i = 0; i < k; i++) {
    cin >> a;
    if (a == 2) two++;
    if (a > 7) {
      seat = (a % 8) * 8;
      a = (a % 8) * 8;
    }
    if (a <= 7) {
      seat -= a;
      if (a % 2 == 1) seat--;
    }
    if (seat < 0) ans = "NO";
  }
  if (two > n * 3 && seat <= 0) ans = "NO";
  cout << ans << endl;
}
