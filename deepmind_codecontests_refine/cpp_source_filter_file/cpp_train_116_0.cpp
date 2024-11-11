#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a, b;
  bool flag = 0;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] > s[i + 1]) {
      a = i;
      b = i + 1;
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl << a - 1 << ' ' << b - 1 << endl;
}
