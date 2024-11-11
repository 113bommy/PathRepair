#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, c = 0;
    cin >> n;
    long long int f = n;
    while (f > 0) {
      f /= 2;
      c++;
    }
    long long int sum = (n * (n + 1) / 2);
    for (int i = 0; i <= c; i++) {
      sum -= (1 << i);
    }
    cout << (sum + 1) << endl;
  }
}
