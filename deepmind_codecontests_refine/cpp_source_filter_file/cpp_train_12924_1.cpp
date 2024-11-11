#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int f[N][12];
char ch[N];
int main() {
  scanf("%s", &ch);
  int n = strlen(ch);
  long long ans = 0;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) {
    int cur = ch[i] - '0';
    if (cur) f[i][cur]++;
    if (i == 0) continue;
    for (int j = cur + 1; j < 11; j++) {
      int k = (1 + cur + j * (j - 1) / 2) % 11;
      f[i][k] += f[i - 1][j];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 11; j++) ans += f[i][j];
  cout << ans << endl;
}
