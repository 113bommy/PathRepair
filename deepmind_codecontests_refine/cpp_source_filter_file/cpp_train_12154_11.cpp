#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return (gcd(b, a % b));
}
int lcm(int a, int b) { return (a / gcd(a, b) * b); }
int mod(int a, int b) {
  if (a < 0)
    return ((b + a) % b);
  else
    return a % b;
}
vector<string> splitAsString(string a) {
  vector<string> v;
  string w;
  stringstream s;
  s << a;
  while (s >> w) v.push_back(w);
  return v;
}
string _UCASE(string a) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] >= 'a' && a[i] <= 'z') a[i] = a[i] - 'a' + 'A';
  return a;
}
string _LCASE(string a) {
  for (int i = 0; i < a.size(); i++)
    if (a[i] >= 'A' && a[i] <= 'Z') a[i] = a[i] - 'A' + 'a';
  return a;
}
int main() {
  int n, m;
  cin >> n >> m;
  char v[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> v[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int b = 0;
      if (i - 1 >= 0 && v[i - 1][j] == '*') b++;
      if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] == '*') b++;
      if (i - 1 >= 0 && j + 1 < m && v[i - 1][j + 1] == '*') b++;
      if (j - 1 >= 0 && v[i][j - 1] == '*') b++;
      if (j + 1 < m && v[i][j + 1] == '*') b++;
      if (i + 1 >= 0 && v[i + 1][j] == '*') b++;
      if (i + 1 >= 0 && j - 1 >= 0 && v[i + 1][j - 1] == '*') b++;
      if (i + 1 >= 0 && j + 1 < m && v[i + 1][j + 1] == '*') b++;
      if (v[i][j] != '.' && v[i][j] != '*' && v[i][j] - '0' != b) {
        cout << "NO" << endl;
        return 0;
      }
      if (b > 0 && v[i][j] - '0' != b) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
