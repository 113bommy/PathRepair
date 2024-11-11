#include <bits/stdc++.h>
using namespace std;
char c;
long long n, k, i, a[1001];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> c;
    a[c]++;
    if (a[c] > k) {
      cout << "NO"
           << "\n";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  return 0;
}
