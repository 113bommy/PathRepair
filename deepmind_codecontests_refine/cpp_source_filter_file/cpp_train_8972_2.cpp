#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
long long n, i, j;
long long v1, v2;
vector<long long> u, d;
bool viv = false;
bool vec(long long a, long long b, long long c) {
  a++, b++, c++;
  cout << 2 << ' ' << a << ' ' << b << ' ' << c << endl;
  long long res;
  cin >> res;
  return res == 1;
}
long long sq(long long a, long long b, long long c) {
  a++, b++, c++;
  cout << 1 << ' ' << a << ' ' << b << ' ' << c << endl;
  long long res;
  cin >> res;
  return res;
}
void norm(vector<long long> &vecc, bool xr) {
  if (vecc.empty()) return;
  xr ^= 1;
  vector<pair<long long, long long> > tos;
  for (auto i : vecc) tos.push_back({sq(i, v1, v2), i});
  sort(tos.rbegin(), tos.rend());
  long long mid = tos.back().second;
  tos.pop_back();
  vector<long long> bef, aft;
  long long vv = v1;
  if (xr) vv = v2;
  for (auto i : tos) {
    if (vec(vv, i.second, mid))
      bef.push_back(i.second);
    else
      aft.push_back(i.second);
  }
  reverse(aft.begin(), aft.end());
  bef.push_back(mid);
  for (auto i : aft) bef.push_back(i);
  vecc = bef;
}
void good(vector<long long> &ans) {
  for (long long i = 0; i < n; i++) ans.push_back(ans[i]);
  vector<long long> rans;
  long long j = 0;
  while (ans[j] != 0) j++;
  for (long long i = j; i < j + n; i++) rans.push_back(ans[i]);
  ans = rans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  v1 = n - 1;
  v2 = n - 2;
  for (long long i = 0; i < n - 2; i++) {
    if (vec(i, v1, v2))
      d.push_back(i);
    else
      u.push_back(i);
  }
  norm(d, 0);
  norm(u, 1);
  vector<long long> ans;
  ans.push_back(v1);
  for (auto i : d) ans.push_back(i);
  ans.push_back(v2);
  for (auto i : u) ans.push_back(i);
  if (!vec(ans[0], ans[1], ans[2])) reverse(ans.begin(), ans.end());
  cout << 0 << ' ';
  good(ans);
  for (auto i : ans) cout << i + 1 << ' ';
  return 0;
}
