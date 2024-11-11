#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3f;
const int NINF = -INF - 1;
const long long int mod = 1e9 + 7;
int pre[MAXN];
int find(int x) { return pre[x] == x ? x : pre[x] = find(pre[x]); }
int T, n, k;
char s[MAXN];
int cnt[MAXN][28];
int main() {
  cin >> T;
  while (T--) {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    vector<int> vec;
    for (int i = 0; i <= n + 1; i++) pre[i] = i;
    for (int i = 0; i < n; i++) {
      if (i + k < n) {
        int a = find(i), b = find(i + k);
        if (a != b) pre[a] = b;
      }
    }
    for (int i = 0; i < n / 2; i++) {
      int a = find(i), b = find(n - i - 1);
      if (a != b) pre[a] = b;
    }
    for (int i = 0; i < n; i++) {
      cnt[find(i)][s[i] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (pre[i] != i) continue;
      int mm = 0, tot = 0;
      for (int j = 0; j < 25; j++) {
        mm = max(cnt[i][j], mm);
        tot += cnt[i][j];
      }
      for (int j = 0; j < 25; j++) cnt[i][j] = 0;
      ans += tot - mm;
    }
    cout << ans << endl;
  }
  return 0;
}
