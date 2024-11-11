#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int n, count = 0;
  cin >> n;
  string s;
  int a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = 0;
  }
  for (int j = 0; j < 4; j++) {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] != '.') {
        a[s[i] - '0']++;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    if (a[i] > 2 * n) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
