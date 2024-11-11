#include <bits/stdc++.h>
using namespace std;
char buf[1000010];
string s;
string t;
int func(void) {
  int N = s.length(), i, j;
  s = s + s;
  for (i = 1;; i++)
    if (s[i] != s[i - 1]) break;
  int init = i;
  while (i < init + N) {
    for (j = i; j < init + N; j++)
      if (s[j] != s[i]) break;
    t += ((j - i >= 2) ? '2' : '1');
    i = j;
  }
  int M = t.length();
  t = t + t;
  int ans = 0;
  for ((i) = 0; (i) < (int)(M); (i)++)
    if (t[i] == '2') {
      ans++;
      for (j = i + 1; j < M; j++)
        if (t[j] == '2') break;
      ans += (j - i - 1) / 2;
    }
  if (ans == 0) ans = M / 2;
  return ans;
}
int main(void) {
  scanf("%s", buf);
  s = buf;
  int ans = func();
  cout << ans << endl;
  return 0;
}
