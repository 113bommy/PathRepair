#include <bits/stdc++.h>
using namespace std;
int N, R;
int ans = -1, p;
char anss[1000010];
string s, t;
void deal(int a, int b) {
  if (p > N - 1) return;
  if (a == 1 && b == 1) {
    if (p == N - 1) {
      anss[p++] = 0;
      t.assign(anss);
      reverse(t.begin(), t.end());
      int tmp = 0;
      for (int i = 1; i < t.size(); i++)
        if (t[i - 1] == t[i]) tmp++;
      if (ans == -1 || tmp < ans) {
        ans = tmp;
        s = t;
      }
    }
    return;
  }
  if (a < 1 || b < 1) return;
  if (a > b) {
    anss[p++] = '1';
    deal(a - b, b);
  } else if (a < b) {
    anss[p++] = '0';
    deal(a, b - a);
  } else
    return;
}
int main() {
  cin >> N >> R;
  for (int i = 1; i <= R; i++) {
    p = 0;
    deal(R, i);
  }
  if (ans == -1)
    puts("IMPOSSIBLE");
  else {
    cout << ans << endl;
    putchar('T');
    int flag = (int)(s[0] - '0');
    for (int i = 0; i < s.size(); i++) {
      if ((int)(s[i] - '0') ^ flag)
        putchar('T');
      else
        putchar('B');
    }
    cout << endl;
  }
  return 0;
}
