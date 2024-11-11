#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i = 0, j = 0;
  string s;
  cin >> n >> k >> s;
  for (i = 1; i < n; i++) {
    while (s[i + j] == s[j] && i + j < n) {
      j++;
    }
    if (i + j == n) {
      break;
    } else
      j = 0;
  }
  cout << s;
  k--;
  while (k--) {
    for (i = j; i < n; i++) {
      cout << s[i];
    }
  }
  return 0;
}
