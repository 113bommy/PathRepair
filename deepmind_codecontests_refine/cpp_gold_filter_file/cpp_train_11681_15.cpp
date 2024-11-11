#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, buf;
vector<pair<long long, long long> > vec[2];
vector<pair<long long, long long> > res[2][2];
pair<long long, long long> zhong[2];
void solve(long long w) {
  long long maxid = 0, maxv = -1;
  for (auto &i : vec[w]) {
    cout << "1 1 2 " << i.first << endl;
    cin >> i.second;
    if (i.second >= maxv) {
      maxid = i.first, maxv = i.second;
      zhong[w] = i;
    }
  }
  for (auto &i : vec[w]) {
    if (i.first == maxid) continue;
    cout << "2 1 " << maxid << " " << i.first << endl;
    cin >> buf;
    if (buf == 1)
      res[w][1].push_back(i);
    else
      res[w][0].push_back(i);
  }
  sort(res[w][0].begin(), res[w][0].end(),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         return a.second < b.second;
       });
  sort(res[w][1].begin(), res[w][1].end(),
       [](pair<long long, long long> a, pair<long long, long long> b) {
         return a.second > b.second;
       });
}
int main() {
  zhong[0] = zhong[1] = make_pair(0, 0);
  cin >> n;
  for (long long i = 3; i <= n; i++) {
    cout << "2 1 2 " << i << endl;
    cin >> buf;
    if (buf == 1)
      vec[1].push_back(make_pair(i, 0));
    else
      vec[0].push_back(make_pair(i, 0));
  }
  solve(0);
  solve(1);
  cout << "0 1 ";
  for (auto i : res[0][0]) cout << i.first << " ";
  if (zhong[0].first != 0) cout << zhong[0].first << " ";
  for (auto i : res[0][1]) cout << i.first << " ";
  cout << "2 ";
  for (auto i : res[1][0]) cout << i.first << " ";
  if (zhong[1].first != 0) cout << zhong[1].first << " ";
  for (auto i : res[1][1]) cout << i.first << " ";
  return 0;
}
