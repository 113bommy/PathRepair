#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 1;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      cnt++;
    }
  }
  cout << min(cnt + 1, n);
}
