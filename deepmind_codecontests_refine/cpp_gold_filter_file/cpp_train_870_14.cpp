#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[100];
  for (int w = 1; w <= n; w++) {
    int a;
    cin >> a;
    s[w] = a;
  }
  int m;
  cin >> m;
  int i;
  for (int b = 1; b <= m; b++) {
    int x, y;
    cin >> x >> y;
    i = x;
    s[i]--;
    int j = 1;
    while (j < y) {
      if (i == 1) {
        j++;
        s[i]--;
        continue;
      }
      s[i - 1]++;
      s[i]--;
      j++;
    }
    j = s[i];
    while (j > 0) {
      if (i == n) {
        j--;
        s[i]--;
        continue;
      }
      s[i + 1]++;
      s[i]--;
      j--;
    }
  }
  for (int r = 1; r <= n; r++) {
    cout << s[r] << endl;
  }
  return 0;
}
