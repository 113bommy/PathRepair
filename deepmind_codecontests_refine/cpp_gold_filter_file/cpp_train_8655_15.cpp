#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, t;
  string s = " ";
  cin >> s;
  t = s.size();
  for (int i = 0; i < t; i = i + 1) {
    if (s[i] == 'a') n = n + 1;
  };
  if (t + 1 <= 2 * n - 1)
    cout << t;
  else {
    n = n + n - 1;
    cout << n;
  }
}
