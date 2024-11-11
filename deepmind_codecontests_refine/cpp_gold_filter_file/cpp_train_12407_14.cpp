#include <bits/stdc++.h>
using namespace std;
char s[107];
int a[107], b[107];
int main() {
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  int mx = 0, tmp = 0;
  for (int i = 0; i <= 200; ++i) {
    tmp = 0;
    for (int j = 0; j < n; ++j) {
      if (i >= b[j] && (i - b[j]) % a[j] == 0) s[j] = '1' - (s[j] - '0');
      if (s[j] == '1') ++tmp;
      if (tmp > mx) mx = tmp;
    }
  }
  cout << mx;
  return 0;
}
