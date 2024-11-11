#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int l[n];
  int r[n];
  if (str[0] == '(') {
    r[0] = 1;
    l[0] = 0;
  } else {
    r[0] = 0;
    l[0] = 1;
  }
  int i, j, k;
  for (i = 0; i < n; i++) {
    if (str[i] == '(') {
      l[i] = l[i - 1];
      r[i] = r[i - 1] + 1;
    } else {
      l[i] = l[i - 1] + 1;
      r[i] = r[i - 1];
    }
  }
  if (l[n - 1] != r[n - 1]) {
    cout << -1;
    return 0;
  }
  int ans = 0;
  for (i = 0; i < n; i++) {
    int cnt = 0;
    if (l[i] > r[i]) {
      cnt++;
      while (r[i] != l[i]) {
        cnt++;
        i++;
      }
    }
    ans += cnt;
  }
  cout << ans;
}
