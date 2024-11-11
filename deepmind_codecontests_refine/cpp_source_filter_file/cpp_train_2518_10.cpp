#include <bits/stdc++.h>
using namespace std;
string s, t;
int sum[2][2];
int ans[5010], top;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    cin >> s >> t;
    int n = s.size();
    s = " " + s;
    t = " " + t;
    sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
    int aa = 0, bb = 0;
    for (int i = 1; i <= n; i += 2) {
      if (s[i] == '0' && s[i + 1] == '1') sum[0][0]++;
      if (s[i] == '1' && s[i + 1] == '0') sum[0][1]++;
      if (t[i] == '0' && t[i + 1] == '1') sum[1][0]++;
      if (t[i] == '1' && t[i + 1] == '0') sum[1][1]++;
      if (s[i] == s[i + 1] && s[i] == '0') aa++;
      if (t[i] == t[i + 1] && t[i] == '0') aa--;
      if (s[i] == s[i + 1] && s[i] == '1') bb++;
      if (t[i] == t[i + 1] && t[i] == '1') bb--;
    }
    if (aa || bb) {
      puts("-1");
      continue;
    }
    int opt = 0;
    int pos = 0, sum1 = 0, sum2 = 0;
    top = 0;
    bool xx = true;
    if (sum[0][0] != sum[1][0]) {
      for (int j = 1; j <= n && xx; j += 2) {
        if (t[j] == '0' && t[j + 1] == '1') sum2--;
        if (t[j] == '1' && t[j + 1] == '0') sum2++;
        if (sum[0][0] + sum1 == sum[1][0] + sum2 ||
            sum[0][1] - sum1 == sum[1][1] - sum2) {
          pos = j + 1;
          reverse(t.begin() + 1, t.begin() + j + 2);
          xx = false;
        }
      }
      for (int i = 1; i <= n && xx; i += 2) {
        if (s[i] == '0' && s[i + 1] == '1') sum1--;
        if (s[i] == '1' && s[i + 1] == '0') sum1++;
        sum2 = 0;
        if (sum[0][0] + sum1 == sum[1][0] + sum2 ||
            sum[0][1] - sum1 == sum[1][1] - sum2) {
          pos = 0;
          reverse(s.begin() + 1, s.begin() + i + 2);
          ans[++top] = i + 1;
          xx = false;
        }
        for (int j = 1; j <= n && xx; j += 2) {
          if (t[j] == '0' && t[j + 1] == '1') sum2--;
          if (t[j] == '1' && t[j + 1] == '0') sum2++;
          if (sum[0][0] + sum1 == sum[1][0] + sum2 ||
              sum[0][1] - sum1 == sum[1][1] - sum2) {
            pos = j + 1;
            reverse(t.begin() + 1, t.begin() + j + 2);
            reverse(s.begin() + 1, s.begin() + i + 2);
            ans[++top] = i;
            xx = false;
          }
        }
      }
      if (xx) {
        puts("-1");
        continue;
      }
    }
    for (int i = 1; i <= n; i += 2) {
      for (int j = i; j <= n; j += 2) {
        if (s[j] == t[i] && s[j + 1] == t[i + 1]) {
          if (j - 1) {
            reverse(s.begin() + 1, s.begin() + j);
            ans[++top] = j - 1;
          }
          if (i != n - 1) {
            reverse(s.begin() + 1, s.begin() + j + 2);
            ans[++top] = j + 1;
          }
          break;
        }
      }
    }
    if (pos) ans[++top] = pos;
    if (pos) reverse(s.begin() + 1, s.begin() + pos + 1);
    printf("%d\n", top);
    for (int i = 1; i <= top; i++) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
}
