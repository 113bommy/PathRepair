#include <bits/stdc++.h>
using namespace std;
int n, m;
string p;
int arr[2000005];
char s[2000005];
int z[2000005];
void zee() {
  int l = 0;
  int r = 0;
  string tmp = p;
  tmp += '#';
  tmp += string(s);
  for (int i = 1; i < tmp.size(); i++) {
    if (r >= i) z[i] = min(z[i - l], r - i + 1);
    while (z[i] + i < tmp.size() && tmp[z[i]] == tmp[i + z[i]]) z[i]++;
    if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1;
  }
}
int main() {
  for (int i = 0; i < 100005; i++) s[i] = '?';
  cin >> n >> m >> p;
  for (int i = 0; i < m; i++) scanf("%d", &arr[i]), arr[i]--;
  if (arr[m - 1] + (int)p.size() - 1 >= n) {
    cout << 0;
    return 0;
  }
  int l = 0;
  for (int i = 0; i < m; i++) {
    int cur = max(l - arr[i], 0);
    int idx = max(l, arr[i]);
    for (; cur < p.size(); cur++, idx++) s[idx] = p[cur];
    l = idx;
  }
  zee();
  for (int i = 0; i < m; i++) {
    int f = p.size();
    if (z[arr[i] + f + 1] < p.size()) {
      cout << 0;
      return 0;
    }
  }
  long long cnt = 1;
  for (int i = 0; i < n; i++)
    if (s[i] == '?') cnt *= 26, cnt %= 1000000007;
  cout << cnt << endl;
}
