#include <bits/stdc++.h>
using namespace std;
char s[100010];
char t[100010];
int main() {
  int n;
  cin >> n;
  scanf("%s", s);
  scanf("%s", t);
  int diff;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      diff = i;
      break;
    }
  }
  int ans = 0;
  int posS = diff + 1;
  int posT = diff;
  int cnt = 0;
  while (posS <= n && posT <= n) {
    if (s[posS] == t[posT]) {
      posS++;
      posT++;
    } else {
      cnt++;
      posT++;
      if (cnt > 1) break;
    }
  }
  if (cnt == 1) ans++;
  posS = diff;
  posT = diff + 1;
  cnt = 0;
  while (posS <= n && posT <= n) {
    if (s[posS] == t[posT]) {
      posS++;
      posT++;
    } else {
      cnt++;
      posS++;
      if (cnt > 1) break;
    }
  }
  if (cnt == 1) ans++;
  cout << ans << endl;
  return 0;
}
