#include <bits/stdc++.h>
using namespace std;
const int limN = 5005;
char cics[26][limN][26];
int cnt[26];
int main() {
  int N;
  char str[limN];
  long double ans = 0;
  scanf("%s", str);
  N = strlen(str);
  for (int i = 0; i < N; i++) {
    int c = str[i] - 'a';
    cnt[c]++;
    for (int j = 1; j < N; j++) {
      cics[c][j][str[(i + j) % N] - 'a']++;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (!cnt[i]) continue;
    int mu = 0;
    for (int j = 1; j < N; j++) {
      int c = 0;
      for (int w = 0; w < 26; w++) {
        if (cics[i][j][w] == 1) c++;
      }
      mu = max(mu, c);
    }
    ans += mu;
  }
  ans /= N;
  printf("%.12Lf\n", ans);
}
