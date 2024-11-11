#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  cin >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  int a[m];
  int b[n - m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  sort(a, a + m);
  int j = 0, k = 0;
  for (int i = 0; i < n; i++) {
    if (i != a[j]) {
      b[k++] = i;
    } else
      j++;
  }
  int len = s[a[0]].length();
  for (int i = 0; i < m; i++) {
    if (s[a[i]].length() != len) {
      cout << "No" << endl;
      return 0;
    }
  }
  int bcnt = n - m;
  for (int i = 0; i < n - m; i++) {
    if (s[b[i]].length() != len) {
      b[i] = -1;
      bcnt--;
    }
  }
  string ans;
  for (int i = 0; i < len; i++) {
    char c = s[a[0]][i];
    int count = 0;
    bool one = 0;
    for (j = 0; j < m; j++) {
      count += c != s[a[j]][i];
    }
    if (count == 0) {
      ans += c;
      one = 1;
    } else {
      ans += '?';
    }
    if (one) {
      for (j = 0; j < k; j++) {
        if (b[j] > -1)
          if (s[b[j]][i] != c) {
            b[j] = -1;
            bcnt--;
          }
      }
    }
  }
  if (bcnt == 0) {
    cout << "Yes" << endl << ans << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
