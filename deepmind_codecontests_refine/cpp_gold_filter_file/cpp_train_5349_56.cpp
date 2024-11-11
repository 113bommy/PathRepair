#include <bits/stdc++.h>
const double pi = 3.14159;
using namespace std;
void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int arr[26];
int main() {
  fast();
  string s;
  cin >> s;
  if (s[0] >= 'a' && s[0] <= 'z') s[0] = (s[0] - 32);
  cout << s << '\n';
  return 0;
}
