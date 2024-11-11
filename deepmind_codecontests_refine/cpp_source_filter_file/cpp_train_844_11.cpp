#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string s = "abcd";
  if (n == 1)
    cout << 'a';
  else if (n == 2)
    cout << 'ab';
  else if (n == 3)
    cout << 'abc';
  else if (n == 4)
    cout << 'abcd';
  else {
    int i = 0, m = n / 4, k = n % 4;
    for (i = 0; i < m; i++) cout << s;
    if (k == 1)
      cout << 'a';
    else if (k == 2)
      cout << "ab";
    else if (k == 3)
      cout << "abc";
  }
  return 0;
}
