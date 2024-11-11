#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, j = 0, c = 0;
  char s1[10000], s2[10000], s3[10000];
  scanf("%s %s", s1, s2);
  n = strlen(s1);
  for (i = n - 1; i >= 0; i--) {
    s3[j++] = s1[i];
  }
  for (i = 0; i < n; i++) {
    if (s1[i] == s3[i]) c++;
  }
  if (c == n)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
