#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str[100];
  for (int i = 0; i < n; i++) {
    cin >> str[i];
  }
  sort(str, str + n);
  int cnt = 1;
  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (str[i] == str[i + 1]) {
      cnt++;
    } else {
      cnt = 1;
    }
    if (cnt >= ans) {
      ans = cnt;
    }
  }
  cout << ans << endl;
}
