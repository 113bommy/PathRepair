#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, c;
  int n, t = 0;
  cin >> n >> s >> c;
  for (int i = 0; i < n; i++) t += min(abs(s[i] - c[i]), 10 - abs(s[i] - c[i]));
  cout << t;
}
