#include <bits/stdc++.h>
using namespace std;
int testCase;
string s;
int iinf = 1e9 + 1;
long long inf = 1e16 + 1;
void solve() {
  long long n;
  cin >> n;
  long long k;
  cin >> k;
  if (k >= n) {
    cout << n;
    return;
  }
  long long extra = n - k;
  cout << (extra * (extra + 1)) / 2 + k - 1;
}
int main() {
  testCase = 1;
  while (testCase--) {
    solve();
    cout << "\n";
  }
}
