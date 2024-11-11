#include <bits/stdc++.h>
using namespace std;
int mp[505][505];
int ans[250005];
int main() {
  int n, m, a, b;
  while (cin >> m >> n >> a >> b) {
    memset(mp, 0, sizeof(mp));
    string s;
    cin >> s;
    int p = 1;
    int k = 1;
    printf("1 ");
    mp[a][b] = 1;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == 'U' && a > 1)
        a -= 1;
      else if (s[i] == 'D' && a < m)
        a += 1;
      else if (s[i] == 'L' && b > 1)
        b -= 1;
      else if (s[i] == 'R' && b < n)
        b += 1;
      if (!mp[a][b]) {
        ans[p++] = 1;
        mp[a][b] = 1;
        k++;
      } else
        ans[p++] = 0;
    }
    if (m == 1 && n == 1) {
      for (int i = 0; i < p; i++) {
        if (i != p - 1)
          printf("%d ", ans[i]);
        else
          printf("0\n");
      }
    } else {
      for (int i = 1; i < p; i++) {
        printf("%d ", ans[i]);
      }
      printf("%d\n", m * n - k);
    }
  }
}
