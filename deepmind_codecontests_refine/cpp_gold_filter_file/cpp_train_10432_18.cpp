#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int INF = 0x3f3f3f3f;
int hang[maxn], lie[maxn], num[maxn];
char s[maxn];
int mp[2100][2100];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j) {
      mp[i][j] = s[j] - '0';
    }
  }
  for (int i = 0; i <= n; ++i) hang[i] = lie[i] = num[i] = 0;
  long long ans = 0;
  for (int i = n; i; --i) {
    for (int j = 1; j < i; ++j) {
      if ((mp[j][i] + lie[i] + hang[j]) % 2 == 1) {
        lie[i]++;
        hang[j]++;
        ans++;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    num[i] += lie[i] + hang[i];
  }
  for (int i = 0; i <= n; ++i) hang[i] = lie[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = n; j > i; --j) {
      if ((mp[j][i] + lie[i] + hang[j]) % 2 == 1) {
        lie[i]++;
        hang[j]++;
        ans++;
      }
    }
  }
  for (int i = 1; i <= n; ++i) num[i] += lie[i] + hang[i];
  for (int i = 1; i <= n; ++i) {
    if ((mp[i][i] + num[i]) % 2 == 1) ans++;
  }
  cout << ans << "\n";
  return 0;
}
