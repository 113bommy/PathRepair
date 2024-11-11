#include <bits/stdc++.h>
using namespace ::std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int f[10];
  f[0] = 0;
  for (int i = 1; i < 10; i++) {
    cin >> f[i];
  }
  int i = 0;
  while (i < n and f[s.at(i) - '0'] < s.at(i) - '0') {
    i++;
  }
  int start = i;
  while (i < n and f[s.at(i) - '0'] >= s.at(i) - '0') {
    i++;
  }
  int end = i;
  for (int i = 0; i < n; i++) {
    if (start <= i and i < end) {
      cout << f[s.at(i) - '0'];
    } else {
      cout << s.at(i);
    }
  }
}
