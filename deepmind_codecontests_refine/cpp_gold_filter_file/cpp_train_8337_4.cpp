#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k, i;
  cin >> n >> k;
  string s;
  cin >> s;
  int p = 0;
  for (i = 0; i < n; i++) {
    if (s.substr(0, i) == s.substr(n - i, i)) p = i;
  }
  for (i = 1; i < k; i++) cout << s.substr(0, n - p);
  cout << s << "\n";
  return 0;
}
