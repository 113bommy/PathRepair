#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1e5;
const long long INF = 1e15, mod = 1e9 + 7, UM = 1e7;
const int inf = 1e9;
long long ask(vector<long long>& v) {
  cout << "? " << int(v.size()) << ' ';
  for (long long i : v) cout << i + 1 << ' ';
  cout << endl;
  long long rt;
  cin >> rt;
  if (rt == -1) exit(0);
  return rt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  int n;
  cin >> n;
  vector<vector<long long> > qq(13);
  vector<long long> msks;
  vector<long long> anss(13);
  for (int mask = (0); mask < ((1 << 13)); ++mask) {
    if (__builtin_popcount(mask) != 6) continue;
    if (int(msks.size()) == n) break;
    for (int i = (0); i < (13); ++i)
      if (mask >> i & 1) qq[i].push_back(int(msks.size()));
    msks.push_back(mask);
  }
  for (int i = (0); i < (13); ++i)
    if (int(qq.size())) anss[i] = ask(qq[i]);
  cout << "! ";
  for (int i = (0); i < (n); ++i) {
    long long out = 0;
    for (int j = (0); j < (13); ++j)
      if (!(msks[i] >> j & 1)) out |= anss[j];
    cout << out << ' ';
  }
  cout << endl;
}
