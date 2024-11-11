#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << "v\n";
      continue;
    }
    cout << string(n / 2, 'a') + (n & 1 ? "bv" : "a") + string(n / 2 - 1, 'a')
         << "\n";
  }
  return 0;
}
