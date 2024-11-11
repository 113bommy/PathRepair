#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == '*') a[i] = 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*') {
      for (int j = 1; j <= n; j++) {
        int cnt = 0, mx = 0;
        for (int k = i; k < n; k += j) {
          if (a[k]) {
            cnt++;
          } else
            cnt = 0;
          mx = max(cnt, mx);
        }
        if (mx >= 5) {
          cout << "YES";
          return 0;
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
