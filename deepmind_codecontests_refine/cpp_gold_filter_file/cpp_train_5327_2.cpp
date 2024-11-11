#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, s, t;
    cin >> n >> s >> t;
    int hasboth = s + t - n;
    cout << max(n - t, n - s) + 1 << endl;
  }
  return 0;
}
