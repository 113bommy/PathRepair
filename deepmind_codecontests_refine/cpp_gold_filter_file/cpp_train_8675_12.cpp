#include <bits/stdc++.h>
using namespace std;
void solve() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  long long width = 1, length = 1;
  for (long long i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "UR" or s == "DL")
      width++;
    else if (s == "UL" or s == "DR")
      length++;
    else {
      width++;
      length++;
    }
  }
  cout << width * length << '\n';
}
