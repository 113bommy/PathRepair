#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
int N, M;
map<long long, long long> mp;
long long arr[MX];
pair<int, int> p[MX];
bool cmp(pair<int, int> &p1, pair<int, int> &p2) {
  if (p1.first == p2.first) return p1.second > p2.second;
  return p1.first < p2.first;
}
vector<int> ans(MX);
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    p[i].first = arr[i];
    p[i].second = i;
  }
  sort(p, p + N, cmp);
  ans[p[0].second] = -1;
  mp[p[0].second]++;
  map<long long, long long>::iterator it;
  for (int i = 1; i < N; i++) {
    it = mp.end();
    it--;
    int ex = it->first;
    if (p[i].second > ex) {
      ans[p[i].second] = -1;
      mp[p[i].second]++;
      continue;
    }
    ans[p[i].second] = ex - p[i].second - 1;
    mp[p[i].second]++;
  }
  for (int i = 0; i < N; i++) cout << ans[i] << " ";
  return 0;
}
