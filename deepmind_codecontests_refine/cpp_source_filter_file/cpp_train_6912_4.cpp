#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  string s;
  cin >> n;
  cin >> s;
  int m = s.size();
  int count = 0;
  for (int i = n - 1; i < m; i += n) {
    if (s[i - 1] == s[i - 2] && s[i - 3] == s[i - 1]) count++;
  }
  cout << count;
  return 0;
}
