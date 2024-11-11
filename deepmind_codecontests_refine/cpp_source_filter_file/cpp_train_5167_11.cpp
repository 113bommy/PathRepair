#include <bits/stdc++.h>
using namespace std;
char a[100005];
int main() {
  int n;
  scanf("%s", a);
  vector<int> v[26];
  for (int j = 0; j < strlen(a); j++) {
    v[a[j] - 'a'].push_back(j + 1);
  }
  int l = strlen(a);
  int mi = 0x3f3f3f3f;
  for (int i = 0; i < 26; i++) {
    int mx = 0;
    int j;
    for (j = 0; j < v[i].size(); j++) {
      if (j == 0)
        mx = v[i][0];
      else
        mx = max(mx, v[i][j] - v[i][j - 1]);
    }
    if (j) mx = max(mx, l - v[i][j - 1]);
    if (mx) mi = min(mi, mx);
  }
  printf("%d\n", mi);
  return 0;
}
