#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int n = 1;
    int tmp = x;
    while (tmp /= 10) n++;
    cout << ((x % 10) - 1) * 10 + (n * (n + 1)) / 2 << endl;
  }
  return 0;
}
