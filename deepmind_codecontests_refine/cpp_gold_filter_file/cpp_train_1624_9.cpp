#include <bits/stdc++.h>
using namespace std;
int n, k, cnt, minl[200010], ans, st;
string S, str[20], tmp;
bool ok[20];
int main() {
  cin >> S;
  n = S.length();
  cin >> k;
  for (int i = 0; i < n; i++) minl[i] = 200010;
  for (int i = 1; i <= k; i++) cin >> str[i];
  for (int i = 1; i <= k; i++) ok[i] = true;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= k; j++)
      if (i != j && str[i].find(str[j]) != -1 && str[i] != str[j])
        ok[i] = false;
  int cnt = 0;
  for (int i = 1; i <= k; i++)
    if (ok[i]) str[++cnt] = str[i];
  k = cnt;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      cnt = str[j].length();
      tmp = S.substr(i, cnt);
      if (tmp == str[j]) {
        if (cnt < minl[i]) minl[i] = cnt;
      }
    }
  }
  k = -1;
  for (int i = 0; i < n; i++) {
    if (minl[i] < 100010) {
      k = i;
      break;
    }
  }
  st = 0;
  ans = 0;
  if (k >= 0) {
    ans = k + minl[k] - 1;
    for (int i = k + 1; i < n; i++) {
      if (minl[i] < 100010) {
        if (i - k - 2 + minl[i] > ans) {
          ans = i - k - 2 + minl[i];
          st = k + 1;
        }
        k = i;
      }
    }
  }
  if (n - k - 1 > ans) {
    st = k + 1;
    ans = n - k - 1;
  }
  cout << ans << " " << st << endl;
}
