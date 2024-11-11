#include <bits/stdc++.h>
using namespace std;
const int Maxn = 400000, key = 701;
int n;
vector<pair<int, string> > nei[Maxn];
vector<long long> h;
string st;
long long sst, ans, kx = 1;
bool mark[Maxn];
void input() {
  int a;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> a >> st;
    nei[a - 1].push_back(make_pair(i, st));
  }
  cin >> st;
}
void hhash() {
  for (auto c : st) sst = (sst * key + c);
}
void Hash(string k) {
  for (auto c : k) {
    h.push_back(h.back() * key + c);
    if ((int)h.size() > (int)st.size()) {
      long long last = h.back() - (h[(int)h.size() - (int)st.size() - 1] * kx);
      if (last == sst) ans++;
    }
  }
}
void clean(int k) {
  for (int i = 0; i < k; i++) h.pop_back();
  ;
}
void dfs(int u) {
  mark[u] = true;
  for (auto v : nei[u])
    if (!mark[v.first]) {
      Hash(v.second);
      dfs(v.first);
      clean((int)v.second.size());
    }
  return;
}
void solve() {
  for (int i = 0; i < (int)st.size(); i++) kx *= key;
  hhash();
  h.push_back(0);
  dfs(0);
}
int main() {
  input();
  solve();
  cout << ans << endl;
  return 0;
}
