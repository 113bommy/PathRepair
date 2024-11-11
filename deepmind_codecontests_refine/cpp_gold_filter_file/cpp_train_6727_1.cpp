#include <bits/stdc++.h>
using namespace std;
bool f(char ch) {
  return (ch != 'a' && ch != 'o' && ch != 'i' && ch != 'e' && ch != 'u');
}
string s;
int n, cnt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  char l1 = 0, l2 = 0;
  for (int i = 0; i < s.length(); i++) {
    if (f(s[i]))
      cnt++;
    else
      cnt = 0;
    if (cnt >= 3 && (s[i] != l1 || s[i] != l2)) {
      cnt = 1;
      cout << " ";
    }
    l2 = l1;
    l1 = s[i];
    cout << s[i];
  }
}
