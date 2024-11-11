#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
template <typename A>
istream& operator>>(istream& fin, vector<A>& v) {
  int n = ((int)(v.size()));
  for (int i = 0; i < n; ++i) fin >> v[i];
  return fin;
}
template <typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& v) {
  fin >> v.first >> v.second;
  return fin;
}
const int C = 31;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int x;
  long long d;
  cin >> x >> d;
  vector<int> sd(C);
  for (int i = 1; i < C; ++i) sd[i] = (1 | (sd[i - 1] << 1));
  vector<int> k;
  int h = C - 1;
  while (x) {
    while (sd[h] > x) --h;
    k.push_back(h);
    x -= sd[h];
  }
  vector<long long> ans;
  for (int i = 0; i < ((int)(k.size())); ++i) {
    long long e = d * i;
    for (int j = 0; j < k[i]; ++j) ans.push_back(e);
  }
  cout << ((int)(ans.size())) << '\n';
  for (int i = 0; i < ((int)(ans.size())); ++i) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
