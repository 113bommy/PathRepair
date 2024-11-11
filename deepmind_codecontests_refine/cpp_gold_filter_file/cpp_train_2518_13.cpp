#include <bits/stdc++.h>
using namespace std;
int T, n;
char s[4000 + 5], t[4000 + 5];
int cnts[10], cntt[10];
vector<int> ans;
void rev(int x) {
  ans.push_back(x);
  reverse(s + 1, s + 1 + x);
}
int hsh(char *s, int i) { return ((s[i - 1] - '0') << 1) | (s[i] - '0'); }
void ini() {
  for (int i = 0; i < 4; i++) cnts[i] = cntt[i] = 0;
  ans.clear();
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    ini();
    n = strlen(s + 1);
    for (int i = 2; i <= n; i += 2) cnts[hsh(s, i)]++;
    for (int i = 2; i <= n; i += 2) cntt[hsh(t, i)]++;
    if (cnts[0] != cntt[0] || cnts[3] != cntt[3] ||
        cnts[1] + cnts[2] != cntt[1] + cntt[2]) {
      puts("-1");
      continue;
    }
    if (cnts[1] == cntt[2]) {
      for (int i = 2; i <= n; i += 2) {
        for (int j = i; j <= n; j += 2) {
          if (s[j] == t[n - i + 1] && s[j - 1] == t[n - i + 2]) {
            if (j - 2 > 0) rev(j - 2);
            rev(j);
            break;
          }
        }
      }
    } else {
      bool flag = 0;
      if (abs(cnts[1] - cnts[2]) < abs(cntt[1] - cntt[2])) {
        swap(s, t);
        flag = 1;
      }
      int cur = 0;
      for (int i = 2; i <= n; i += 2) {
        if (hsh(s, i) == 1)
          cur++;
        else if (hsh(s, i) == 2)
          cur--;
        if (2 * cur == cnts[1] - cnts[2] + cntt[1] - cntt[2]) {
          rev(i);
          break;
        }
      }
      for (int i = 2; i <= n; i += 2) {
        for (int j = i; j <= n; j += 2) {
          if (s[j - 1] == t[n - i + 2] && s[j] == t[n - i + 1]) {
            if (j - 2 > 0) rev(j - 2);
            rev(j);
            break;
          }
        }
      }
      if (flag) reverse(ans.begin(), ans.end());
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
  }
}
