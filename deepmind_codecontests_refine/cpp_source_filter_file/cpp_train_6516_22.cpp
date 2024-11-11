#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n;
  cin >> n;
  string s = "aabbc";
  for (i = 0, j = 0; i < n; i++, j++) {
    if (j == s.length()) j = 0;
    cout << s[j];
  }
  cout << endl;
  return 0;
}
