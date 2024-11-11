#include <bits/stdc++.h>
using namespace std;
int n, Q;
const int maxn = (1 << 17);
pair<int, int> q[maxn];
map<int, int> mp;
long long sum[4 * maxn][5];
int cnt[4 * maxn];
void update(int v) {
  cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
  for (int i = 0; i < 5; i++)
    sum[v][i] = sum[v * 2][i] + sum[v * 2 + 1][(i - cnt[v * 2] % 5 + 5) % 5];
  return;
}
int main() {
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    string s;
    cin >> s;
    if (s[0] == 's') {
      q[i].first = 2, q[i].second = 0;
      continue;
    }
    int x;
    scanf("%d", &x);
    if (s[0] == 'a')
      q[i] = make_pair(0, x);
    else if (s[0] == 'd')
      q[i] = make_pair(1, x);
    mp[x] = 0;
  }
  n = 0;
  for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    it->second = n++;
  for (int i = 0; i < Q; i++) {
    if (q[i].first == 2)
      cout << sum[1][2] << endl;
    else {
      int pos = maxn + mp[q[i].second];
      cnt[pos] = 1 - q[i].first;
      sum[pos][0] = cnt[pos] * (long long)q[i].second;
      while (pos > 1) {
        pos /= 2;
        update(pos);
      }
    }
  }
  return 0;
}
