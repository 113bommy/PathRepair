#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double EPS = 1e-9;
vector<int> ur[30];
int sz[30];
char a[10005];
char b[1000005];
int main() {
  scanf("%s", a);
  scanf("%s", b);
  int n = strlen(a);
  int m = strlen(b);
  memset(sz, 0, sizeof(sz));
  for (int i = 0; i < n; i++) {
    ur[a[i] - 'a'].push_back(i + 1);
    sz[a[i] - 'a']++;
  }
  int ans = 1;
  int cur = 0;
  for (int i = 0; i < m; i++) {
    if (!sz[b[i] - 'a']) {
      printf("-1\n");
      return 0;
    }
    int p = upper_bound(ur[b[i] - 'a'].begin(), ur[b[i] - 'a'].end(), cur) -
            ur[b[i] - 'a'].begin();
    if (p == sz[b[i] - 'a']) {
      ans++;
      cur = ur[b[i] - 'a'][0];
    } else
      cur = ur[b[i] - 'a'][p];
  }
  printf("%d\n", ans);
  return 0;
}
