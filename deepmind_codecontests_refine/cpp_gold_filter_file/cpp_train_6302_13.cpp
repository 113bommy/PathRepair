#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n, i = 1;
  cin >> n;
  while (s.size() < n) {
    s += to_string(i++);
  }
  cout << s[n - 1];
  return 0;
}
