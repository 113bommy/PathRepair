#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if ((n / 2) % 2 or n % 2)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}
