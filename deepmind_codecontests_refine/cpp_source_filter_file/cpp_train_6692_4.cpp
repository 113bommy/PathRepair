#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int sum = (n % 10 - 1) * 10;
    if (1 < n) sum += 1;
    if (10 < n) sum += 2;
    if (100 < n) sum += 3;
    if (1000 < n) sum += 4;
    cout << sum << "\n";
  }
}
