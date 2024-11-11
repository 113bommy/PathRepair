#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char str1[N][12], str2[N][12];
char ip1[N][16], ip2[N][16];
bool cmp(int x, int y) {
  int len1 = strlen(ip1[x]);
  int len2 = strlen(ip2[y]);
  if (len1 != len2 - 1) return false;
  for (int i = 0; i < len2 - 1; i++) {
    if (ip1[x][i] != ip2[y][i]) return false;
  }
  return true;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf(" %s%s", str1[i], ip1[i]);
  for (int i = 0; i < m; i++) scanf(" %s%s", str2[i], ip2[i]);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (cmp(j, i)) {
        printf("%s %s #%s\n", str2[i], ip2[i], str1[j]);
        break;
      }
    }
  }
  return 0;
}
