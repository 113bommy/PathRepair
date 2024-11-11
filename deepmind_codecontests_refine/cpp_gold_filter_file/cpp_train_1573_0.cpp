#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n == 2)
    cout << "2"
         << "\n";
  else {
    long long int count = 1;
    long long int c = 2;
    while (c <= n) {
      count++;
      c *= 2;
    }
    cout << count << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
