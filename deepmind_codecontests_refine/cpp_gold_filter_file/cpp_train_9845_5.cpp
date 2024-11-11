#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  int x = 0;
  int v = 0;
  cin >> n;
  string s;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == 'A') {
      x += 1;
    } else if (s[i] == 'D') {
      v += 1;
    }
  }
  if (x > v)
    cout << "Anton" << '\n';
  else if (x < v)
    cout << "Danik" << '\n';
  else
    cout << "Friendship" << '\n';
  return 0;
}
