#include <bits/stdc++.h>
using namespace std;
char s[200004];
char t[200004];
int R[200004];
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int m = strlen(t);
  int n = strlen(s);
  int j = m - 1;
  int i = n - 1;
  R[m] = n;
  while (s[i] != t[j]) {
    i--;
  }
  R[j--] = i;
  while (j >= 0) {
    i--;
    while (s[i] != t[j]) i--;
    R[j] = i;
    j--;
  }
  j = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, R[j] - i);
    if (j < m && s[i] == t[j]) j++;
  }
  cout << ans << '\n';
}
