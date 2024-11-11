#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int dif = n - k;
  string s;
  char a = 'a', r;
  for (int i = 0; i < n; i++) {
    if (a > 'a' + k - 1) a = 'a';
    if (dif > 0 && a > 'b' && r != s[i - 1]) {
      r = a - 2;
      s += r;
      dif--;
      continue;
    }
    s += a;
    a++;
  }
  cout << s << endl;
}
