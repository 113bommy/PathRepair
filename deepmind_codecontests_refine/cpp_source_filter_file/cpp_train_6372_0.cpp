#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, d = 0, s1 = 0;
  cin >> n >> k;
  string s;
  cin >> s;
  char b;
  map<char, int> m;
  m[s[n]] = 1;
  for (int i = 1; i <= k; i++) {
    cin >> b;
    m[b] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (m[s[i]] == 1) {
      d++;
    } else {
      d = 0;
    }
    if (m[s[i + 1]] == 0) {
      s1 += d * (d + 1) / 2;
    }
  }
  if (d == 0)
    cout << s1;
  else
    cout << s1 + d * (d + 1) / 2;
}
