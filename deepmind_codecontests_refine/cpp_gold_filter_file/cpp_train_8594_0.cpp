#include <bits/stdc++.h>
using namespace std;
char buff[1000006];
int su[1000006], sd[1000006];
long long sul[1000006], sdl[1000006];
int iu[1000006], id[1000006];
void solve() {
  int n;
  cin >> n;
  scanf("%s", buff + 1);
  su[0] = 0, sd[0] = 0;
  iu[0] = 0, id[0] = 0;
  for (int i = 1; i <= (n); ++i) {
    su[i] = su[i - 1] + (buff[i] == 'U');
    sd[i] = sd[i - 1] + (buff[i] == 'D');
    if (buff[i] == 'U')
      iu[su[i]] = i;
    else
      id[sd[i]] = i;
  }
  sul[0] = sdl[0] = 0;
  for (int i = 1; i <= (n); ++i) {
    sul[i] = sul[i - 1] + (buff[i] == 'U') * i;
    sdl[i] = sdl[i - 1] + (buff[i] == 'D') * i;
  }
  for (int pos = 1; pos <= (n); ++pos) {
    int cl = su[pos - 1] - su[0];
    int cr = sd[n] - sd[pos];
    long long ans;
    if (buff[pos] == 'U') {
      if (cr > cl) {
        cr = cl + 1;
        ans = pos;
      } else {
        cl = cr;
        ans = n - pos + 1;
      }
    } else {
      if (cl > cr) {
        cl = cr + 1;
        ans = n - pos + 1;
      } else {
        cr = cl;
        ans = pos;
      }
    }
    int le = iu[su[pos - 1] - cl];
    ans += 2LL * pos * cl;
    ans -= 2LL * (sul[pos - 1] - sul[le]);
    int re = id[sd[pos] + cr];
    ans += 2LL * (sdl[re] - sdl[pos]);
    ans -= 2LL * pos * cr;
    printf("%I64d ", ans);
  }
  putchar('\n');
}
int main() {
  solve();
  return 0;
}
