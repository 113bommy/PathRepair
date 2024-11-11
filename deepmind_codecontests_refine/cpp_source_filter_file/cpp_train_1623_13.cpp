#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt = (s[i] == 'N') ? cnt + 1 : 0;
    if (cnt > k) {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i <= n - k;) {
    int j = i;
    while (j < n && s[j] != 'Y') j++;
    int cnt_y = j;
    if (j - i == k) {
      cout << "YES";
      return 0;
    }
    for (j = i; j <= cnt_y - k; j++) {
      if ((j == 0 || s[j - 1] == '?') && (j + k == n || s[j + k] == '?')) {
        cout << "YES";
        return 0;
      }
    }
    i = cnt_y + 1;
  }
  cout << "NO";
}
