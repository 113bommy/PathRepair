#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char str[N];
vector<int> answer;
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  int T;
  scanf("%d", &T);
  for (int cas = 0; cas < T; cas++) {
    scanf("%s", str);
    int n = strlen(str);
    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++) {
      cnt[str[i] - '0']++;
    }
    int canSupport = 0;
    bool ok = false;
    for (int i = n - 1; ~i; i--) {
      cnt[str[i] - '0']--;
      for (int become = str[i] - '0' - 1; become >= 0; become--) {
        if (become == 0 && !i) break;
        int extra = 0;
        cnt[become]++;
        for (int odd = 0; odd < 10; odd++)
          if (cnt[odd] & 1) {
            extra++;
          }
        if (extra <= canSupport && (canSupport - extra) % 2 == 0) {
          str[i++] = become + '0';
          for (int _ = 0; _ < canSupport - extra; _++) {
            str[i++] = '9';
          }
          for (int odd = 0; odd < 10; odd++)
            if (cnt[odd] & 1) {
              str[i++] = '0' + odd;
            }
          ok = true;
          break;
        }
        cnt[become]--;
      }
      if (ok) {
        break;
      }
      canSupport++;
    }
    if (ok) {
      printf("%s\n", str);
    } else {
      for (int i = 0; i < n - 2; i++) {
        printf("9");
      }
      puts("");
    }
  }
  return 0;
}
