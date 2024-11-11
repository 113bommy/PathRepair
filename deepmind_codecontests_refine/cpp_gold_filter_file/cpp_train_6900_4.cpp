#include <bits/stdc++.h>
using namespace std;
void solve(string s, int n) {
  cout << "$";
  int i = 0;
  int k = 0;
  while (i < n && s[i] != '.') k++, i++;
  i = 0;
  for (; i < k % 3; i++) cout << s[i];
  if (i < n && k % 3 > 0 && s[i] != '.') cout << ",";
  int l = 0;
  while (i < n && s[i] != '.') {
    cout << s[i];
    l++;
    if (l % 3 == 0 && i != n - 1 && i != k - 1) cout << ",";
    i++;
  }
  cout << ".";
  i++;
  int j = 0;
  while (j < 2) {
    if (i >= n)
      cout << "0";
    else
      cout << s[i], i++;
    j++;
  }
}
int main() {
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] != '-')
    solve(s, n);
  else {
    cout << "(";
    for (int i = 0; i < n - 1; i++) s[i] = s[i + 1];
    n--;
    solve(s, n);
    cout << ")";
  }
}
