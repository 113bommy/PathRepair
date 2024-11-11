#include <bits/stdc++.h>
using namespace std;
string s;
int l;
long long n, t;
int main() {
  cin >> s;
  l = s.length() - 1;
  if (s[l] == 'f') t = 1;
  if (s[l] == 'e') t = 2;
  if (s[l] == 'd') t = 3;
  if (s[l] == 'a') t = 4;
  if (s[l] == 'b') t = 5;
  if (s[l] == 'c') t = 6;
  for (int i = 0; i < l; ++i) n = n * 10 + (s[i] - '0');
  int p = (n - 1) / 4 * 4;
  t += p;
  t += p / 2 * 6;
  n = (n - 1) % 4 + 1;
  if (n % 2 == 0) t += 7;
  cout << t;
  return 0;
}
