#include <bits/stdc++.h>
using namespace std;
int n, m;
char pic[110][10010];
long long ans = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", pic[i] + 1);
    pic[i][0] = '#';
    pic[i][m + 1] = '#';
  }
  int now = 1, l, r, len;
  int toward = 1;
  bool flag = 0;
  for (int i = 1; i < n; ++i) {
    l = now, r = now;
    while (1) {
      if (pic[i + 1][now] == '.') {
        ans++;
        break;
      }
      if (toward == 1) {
        ans += r - now;
        if (pic[i][r + 1] == '.') {
          r++;
          ans++;
          now = r;
        } else if (pic[i][r + 1] == '+') {
          pic[i][r + 1] = '.';
          ans++;
          now = r;
          toward = -1;
        } else if (pic[i][r + 1] == '#') {
          if (pic[i][l - 1] == '#') {
            puts("NEVER");
            return 0;
          }
          ans++;
          now = r;
          toward = -1;
        }
      } else {
        ans += now - l;
        if (pic[i][l - 1] == '.') {
          l--;
          ans++;
          now = l;
        } else if (pic[i][l - 1] == '+') {
          pic[i][l - 1] = '.';
          ans++;
          now = l;
          toward = 1;
        } else if (pic[i][l - 1] == '#') {
          if (pic[i][r + 1] == '#') {
            puts("Never");
            return 0;
          }
          ans++;
          now = l;
          toward = 1;
        }
      }
    }
  }
  cout << ans;
}
