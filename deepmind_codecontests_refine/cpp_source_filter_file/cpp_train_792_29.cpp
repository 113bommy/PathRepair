#include <bits/stdc++.h>
using namespace std;
int hcnt[105][256];
int vcnt[105][256];
int n, m;
char cross[105][105];
int main() {
  cin >> n >> m;
  gets(cross[0]);
  for (int i = 0; i < n; i++) {
    gets(cross[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      hcnt[i][cross[i][j]]++;
      vcnt[j][cross[i][j]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((hcnt[i][cross[i][j]] == 1) && (vcnt[j][cross[i][j]] == 1))
        putchar(cross[i][j]);
    }
  }
  return 0;
}
