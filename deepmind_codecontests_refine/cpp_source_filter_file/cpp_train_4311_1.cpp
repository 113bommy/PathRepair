#include <bits/stdc++.h>
using namespace std;
int cnt[1000];
char str[1111];
int len;
int isok(int m, int n) {
  int l = n, te;
  for (int i = 'a'; i < 'z'; i++) {
    if (cnt[i] % m == 0)
      te = cnt[i] / m;
    else
      te = cnt[i] / m + 1;
    l -= te;
    if (l < 0) return 0;
  }
  return 1;
}
void put(int m, int n) {
  int l = n, te;
  for (int i = 'a'; i < 'z'; i++) {
    if (cnt[i] % m == 0)
      te = cnt[i] / m;
    else
      te = cnt[i] / m + 1;
    l -= te;
    while (te--) printf("%c", i);
  }
  while (l--) printf("a");
  cout << endl;
}
int main(int argc, const char *argv[]) {
  int n;
  while (~scanf("%s %d", str, &n)) {
    memset(cnt, 0, sizeof(cnt));
    len = strlen(str);
    for (int i = 0; i < len; i++) {
      cnt[str[i]]++;
    }
    int l = 1, r = len, ans = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (isok(m, n))
        r = m - 1, ans = m;
      else
        l = m + 1;
    }
    cout << ans << endl;
    if (ans != -1) put(ans, n);
  }
  return 0;
}
