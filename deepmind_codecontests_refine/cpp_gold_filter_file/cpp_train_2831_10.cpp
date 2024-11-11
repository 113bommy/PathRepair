#include <bits/stdc++.h>
using namespace std;
char str[1000005];
int d[1000005];
int p[30][30];
int n, m;
long long sum = 0;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", str);
  for (int i = 0; i < n - 1; i++)
    if (str[i] != str[i + 1]) {
      char a = str[i], b = str[i + 1];
      p[a - 'a'][b - 'a']++, p[b - 'a'][a - 'a']++;
    }
  for (int i = 1; i <= (1 << m) - 1; i++) d[i] = 1e9;
  for (int i = 1; i <= (1 << m) - 1; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if ((i >> j & 1) ^ (i >> k & 1)) cnt += p[j][k];
      }
    }
    for (int j = 0; j < m; j++) {
      if (i >> j & 1) d[i] = min(d[i], d[i - (1 << j)] + cnt);
    }
  }
  cout << d[(1 << m) - 1];
}
