#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
const long long int M = 1e9 + 7;
const long double PI = 3.14159265;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t, l, r, n;
  string str;
  t = 1;
  while (t--) {
    cin >> n >> str;
    l = count(str.begin(), str.end(), 'L');
    r = count(str.begin(), str.end(), 'R');
    cout << l + r + 1;
  }
}
