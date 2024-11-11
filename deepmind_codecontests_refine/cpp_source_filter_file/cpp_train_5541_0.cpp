#include <bits/stdc++.h>
using namespace std;
const double EXP = 1e-9;
const int INF = 0x3f3f3f3f;
const long long MINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 5;
bool cmp(int a, int b) { return a >= b; }
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  string s[105];
  int a[105];
  int cnt[105];
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < m; i++) cin >> s[i];
    memset(cnt, 0, sizeof(cnt));
    cnt[0]++;
    for (int i = 1; i < m; i++) {
      bool flag = true;
      for (int j = 0; j < i; j++) {
        if (s[i] == s[j]) {
          cnt[j]++;
          flag = false;
          break;
        }
      }
      if (flag) cnt[i]++;
    }
    sort(cnt, cnt + m, cmp);
    int sum = 0;
    for (int i = 0; i < m; i++) {
      sum += a[i] * cnt[i];
    }
    cout << sum << " ";
    sum = 0;
    for (int i = 0; i < m; i++) {
      sum += a[n - i - 1] * cnt[i];
    }
    cout << sum << endl;
  }
  return 0;
}
