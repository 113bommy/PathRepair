#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592654;
const int mod = (int)(1e9) + 7, N = (int)(1e7);
void m3lsh() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int n, m, c, x, y, z, arr[N], a, b;
bool isvowel(char ch) {
  string a = "aeiou";
  for (auto i : a)
    if (i == tolower(ch)) return true;
  return false;
}
int main() {
  m3lsh();
  string a;
  cin >> a;
  for (auto i : a)
    if (isvowel(i) || (isdigit(i) && (i - '0') % 2 == 0)) c++;
  cout << c << '\n';
  return 0;
}
