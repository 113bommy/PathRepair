#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, k;
  cin >> n;
  string s;
  cin >> s;
  for (i = 1; i < n; i++) {
    if (s[i] < s[i - 1]) {
      cout << "YES\n";
      cout << i << " " << i + 1 << '\n';
      return 0;
    }
  }
  cout << "NO\n";
}
