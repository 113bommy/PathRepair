#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long int a = 0, l, b = 0, c = 0, d = 10000007;
  l = s.length();
  for (int i = 0; i < l; i++) {
    if (s[i] >= 'a') {
      b++;
    }
    if (s[i] <= 'Z') {
      c++;
    }
  }
  if (b == l or c == l) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < l; i++) {
    if (s[i] >= 'a') {
      b--;
    }
    d = min(d, b + a);
    if (s[i] <= 'Z') {
      a++;
    }
  }
  cout << d;
  return 0;
}
