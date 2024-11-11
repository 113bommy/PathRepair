#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  if (k >= (n * (n - 1)) / 2) {
    cout << "no solution\n";
    return 0;
  } else {
    for (int y = 0; y < n; y++) {
      cout << 0 << " " << y << "\n";
    }
  }
  return 0;
}
