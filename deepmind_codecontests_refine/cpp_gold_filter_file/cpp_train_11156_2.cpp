#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 1e6 + 10;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const int M = 50000 + 5;
int str[110000];
int mp[1100][1100];
void prime() {
  str[1] = 1;
  for (int i = 2; i <= 11000; i++) {
    if (!str[i]) {
      for (int j = i * i; j <= 11000; j += i) str[j] = 1;
    }
  }
}
int main() {
  prime();
  int n;
  while (~scanf("%d", &n)) {
    memset(mp, 0, sizeof(mp));
    int ans = 0;
    for (int i = 1; i < n; i++) {
      mp[i][i + 1] = 1;
      ans++;
    }
    mp[1][n] = 1;
    ans++;
    int i = 1, j = n - 1;
    while (j - i > 0) {
      if (!str[ans]) break;
      mp[i][j] = 1;
      ans++;
      i++;
      j--;
    }
    printf("%d\n", ans);
    for (int i = 0; i < 1008; i++) {
      for (int j = 0; j < 1008; j++) {
        if (mp[i][j]) printf("%d %d\n", i, j);
      }
    }
  }
  return 0;
}
