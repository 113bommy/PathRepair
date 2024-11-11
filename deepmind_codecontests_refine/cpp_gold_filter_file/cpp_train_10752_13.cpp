#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int n;
vector<int> freq(110, 0), in;
int can(int v, int o) {
  vector<int> last(n + 5, -1);
  int bal = freq[v];
  last[bal] = 0;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (in[i] == v)
      bal--;
    else if (in[i] == o)
      bal++;
    if (last[bal] == -1)
      last[bal] = i + 1;
    else
      ret = max(ret, i + 1 - last[bal]);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  in.assign(n, 0);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    in[i] = k;
    freq[k]++;
  }
  int v = 1;
  for (int i = 0; i < 110; i++)
    if (freq[i] > freq[v]) v = i;
  int ans = 0;
  int m = *max_element(in.begin(), in.end());
  for (int i = 1; i <= m; i++) {
    if (i == v) continue;
    ans = max(ans, can(v, i));
  }
  cout << ans << endl;
}
