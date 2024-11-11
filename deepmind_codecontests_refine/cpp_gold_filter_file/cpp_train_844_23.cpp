#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s = "abcdefghijklmnopqrstuvwxyz";
  cin >> n;
  for (int i = 0; i < n; i++) cout << s[i % 4];
  return 0;
}
