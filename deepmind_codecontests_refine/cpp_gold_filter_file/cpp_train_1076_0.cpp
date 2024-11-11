#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e5 + 7;
int n, a[N], cnt = 1, last = 1;
long long pre[N], power[N];
vector<int> ind[N];
vector<pair<int, int> > rep;
map<int, int> mp;
void same(int i, int j) {
  if (j - i + j - 1 > n) return;
  long long part1 = pre[j - 1] - pre[i - 1] * power[j - i],
            part2 = pre[j - i + j - 1] - pre[j - 1] * power[j - i];
  if (part1 == part2) rep.push_back(make_pair(j - i, i));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  power[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mp[a[i]] == 0) mp[a[i]] = cnt++;
    ind[mp[a[i]]].push_back(i);
    pre[i] = pre[i - 1] * M + a[i];
    power[i] = power[i - 1] * M;
  }
  for (int i = 1; i < cnt; i++)
    for (int j = 0; j < ind[i].size(); j++)
      for (int k = j + 1; k < ind[i].size(); k++) same(ind[i][j], ind[i][k]);
  sort(rep.begin(), rep.end());
  for (int i = 0; i < rep.size(); i++)
    if (last <= rep[i].second) last = rep[i].second + rep[i].first;
  cout << n - last + 1 << endl;
  for (int i = last; i <= n; i++) cout << a[i] << " ";
  return 0;
}
