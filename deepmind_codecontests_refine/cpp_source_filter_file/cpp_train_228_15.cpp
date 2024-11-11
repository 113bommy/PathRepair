#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
int sum[maxn][26], cnt[26];
char s[maxn];
int main() {
  int n, x, T, y;
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &x);
    scanf("%s", s + 1);
    for (int i = 0; i < 26; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        sum[i][j] = sum[i - 1][j];
      }
      sum[i][s[i] - 'a']++;
    }
    for (int i = 0; i <= x; i++) {
      if (i == x)
        y = n;
      else
        scanf("%d", &y);
      for (int j = 0; j < 26; j++) {
        cnt[j] += sum[y][j];
      }
    }
    for (int i = 0; i < 26; i++) cout << cnt[i] << " ";
    cout << endl;
  }
}
