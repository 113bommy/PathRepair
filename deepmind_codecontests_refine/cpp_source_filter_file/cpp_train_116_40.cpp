#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  bool flag = false;
  int i;
  for (i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      flag = true;
      break;
    }
  }
  if (!flag)
    cout << "NO";
  else {
    cout << "YES" << '\n';
    cout << i << " " << i + 1;
  }
}
