#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    long long n, x;
    cin >> n >> x;
    long long deg = 0;
    for (long long int i = 0; i < n - 1; i++) {
      long long u, v;
      cin >> u >> v;
      if (u == x || v == x) deg++;
    }
    if (deg == 1) {
      cout << "Ayush"
           << "\n";
    } else {
      if ((n - 3 + 1) % 2 == 0) {
        cout << "Ayush"
             << "\n";
      } else {
        cout << "Ashish"
             << "\n";
      }
    }
  }
}
