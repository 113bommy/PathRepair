#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long double count = 0;
    while (n > 0) {
      count += n;
      n /= 2;
    }
    cout << count << "\n";
  }
}
