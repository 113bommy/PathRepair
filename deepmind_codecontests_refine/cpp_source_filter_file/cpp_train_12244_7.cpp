#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int p = 1;
  char a = '1';
  for (int i = 0; i < n;) {
    if (s[i] == a) {
      ++p;
      ++i;
      if (p > k) {
        cout << "NO";
        return 0;
      }
    } else {
      p = 1;
      a = s[i];
    }
  }
  cout << "YES";
  return 0;
}
