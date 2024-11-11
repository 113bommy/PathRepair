#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, L = 0, R = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) (s[i] != s[i - 1]) ? ++L : ++R;
  cout << L + min(2, R);
}
