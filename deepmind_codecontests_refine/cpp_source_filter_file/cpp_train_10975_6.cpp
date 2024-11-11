#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n;
bool a(int aa) {
  int pos = 0;
  int m = 0;
  for (int i = int(0); i < int(n); i++) {
    if (s[i] == 'L') pos--;
    if (s[i] == 'R') pos++;
    if (pos < aa) pos++;
    if (i != n - 1) m = max(pos, m);
  }
  if (pos > m)
    return true;
  else
    return false;
}
int aaa() {
  int l = -1000000;
  int r = 0;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a(mid)) {
      ans = max(ans, -mid);
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return ans + 1;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int pos = 0;
  if (s[n - 1] == 'L') {
    for (int i = int(0); i < int(n); i++) {
      if (s[i] == 'R')
        s[i] = 'L';
      else
        s[i] = 'R';
    }
  }
  int maxPos = 0;
  int jc = 1;
  for (int i = int(0); i < int(n); i++) {
    jc = 0;
    if (s[i] == 'L')
      pos--;
    else
      pos++;
    if (pos > maxPos) {
      maxPos = pos;
      jc = 1;
    }
  }
  if (jc) {
    cout << 1 << endl;
    return 0;
  }
  cout << aaa() << endl;
}
