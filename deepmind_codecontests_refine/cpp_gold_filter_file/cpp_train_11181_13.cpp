#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 55;
const long long inf = 1231232132131;
char s1[maxn];
char s2[maxn];
long long mp[30][30];
void floyd() {
  for (long long k = 0; k < 26; k++) {
    for (long long i = 0; i < 26; i++) {
      if (mp[i][k] == inf) continue;
      for (long long j = 0; j < 26; j++) {
        if (mp[i][k] + mp[k][j] < mp[i][j]) {
          mp[i][j] = mp[i][k] + mp[k][j];
        }
      }
    }
  }
}
int main() {
  cin >> s1 >> s2;
  long long m;
  cin >> m;
  memset(mp, 0x3f, sizeof mp);
  for (long long i = 1; i <= m; i++) {
    char u, v;
    cin >> u >> v;
    long long w;
    cin >> w;
    long long a = u - 'a';
    long long b = v - 'a';
    mp[a][b] = min(mp[a][b], w);
  }
  long long l1 = strlen(s1);
  long long l2 = strlen(s2);
  if (l1 != l2) {
    printf("-1\n");
    return 0;
  }
  floyd();
  for (long long i = 0; i < 26; i++) {
    mp[i][i] = 0;
  }
  long long ans = 0;
  char s[maxn];
  for (long long i = 0; i < l1; i++) {
    long long to = -1;
    long long Min = inf;
    for (long long k = 0; k < 26; k++) {
      if (Min > mp[s1[i] - 'a'][k] + mp[s2[i] - 'a'][k]) {
        to = k;
        Min = mp[s1[i] - 'a'][k] + mp[s2[i] - 'a'][k];
      }
    }
    if (to == -1) {
      ans += inf;
      break;
    }
    s[i] = to + 'a';
    ans += Min;
  }
  if (ans >= inf) {
    printf("-1\n");
    return 0;
  }
  printf("%lld\n", ans);
  for (long long i = 0; i < l1; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
  return 0;
}
