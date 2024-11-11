#include <bits/stdc++.h>
using namespace std;
bool check[26];
int main() {
  int n, k, sub = 0, count = 0;
  string s;
  char ch;
  cin >> n >> k >> s;
  while (k--) {
    cin >> ch;
    check[ch - 'a'] = 1;
  }
  for (int i = 0; i <= n; i++) {
    if (check[s[i] - 'a'] == 0) {
      sub += count * (count + 1) / 2;
      count = 0;
    } else {
      count++;
    }
  }
  cout << sub;
  return 0;
}
