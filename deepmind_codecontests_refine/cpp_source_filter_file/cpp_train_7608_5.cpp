#include <bits/stdc++.h>
using namespace std;
int n, m, q, k;
int w[15];
int num[10000];
int v[5555][1300];
string s;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> q;
  int sum = 0;
  for (int i = 0; i < n; ++i) cin >> w[i], sum += w[i];
  for (int i = 0; i < m; ++i) {
    int tp = 0;
    cin >> s;
    for (int j = 0; j < n; ++j) tp += (s[j] - '0') << j;
    num[tp]++;
  }
  for (int i = 0; i < (1 << n); ++i) {
    int wu = 0;
    for (int j = 0; j < (1 << n); ++j) {
      if (!num[j]) continue;
      wu = 0;
      for (int l = 0; l < n; ++l)
        if ((i & (1 << l)) == (j & (1 << l))) wu += w[l];
      v[i][wu] += num[j];
    }
    for (int j = 1; j <= sum; ++j) v[i][j] += v[i][j - 1];
  }
  while (q--) {
    int tp = 0;
    cin >> s >> k;
    for (int i = 0; i < n; ++i) tp += (s[i] - '0') << i;
    cout << v[tp][k] << ('\n');
  }
}
