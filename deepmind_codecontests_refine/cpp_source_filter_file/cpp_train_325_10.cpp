#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = n - y - 1; i < n; i++) {
    if (i == n - y - 1) {
      if (str[i] != '1') cnt++;
    } else {
      if (str[i] == '1') cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
