#include <bits/stdc++.h>
using namespace std;
const int N = 202;
const int mod = 1e9 + 7, b = 33;
long long pot[N];
map<int, int> ha[N];
string str;
vector<int> h;
void prep(string &str, vector<int> &hh) {
  hh = vector<int>(str.size() + 1, 0);
  for (int i = 0; i < str.size(); i++) {
    hh[i + 1] = 1LL * hh[i] * b % mod;
    hh[i + 1] += str[i] - 'a' + 1;
    hh[i + 1] %= mod;
  }
}
int getH(vector<int> &hh, int l, int r) {
  return ((1LL * hh[r] - 1LL * hh[l - 1] * pot[r - l + 1]) % mod + mod) % mod;
}
void pr(string &str, map<int, int> &hh) {
  vector<int> hx;
  prep(str, hx);
  for (int l = 1; l <= str.size(); l++)
    for (int r = l; r <= str.size(); r++) {
      hh[getH(hx, l, r)]++;
    }
}
int main(void) {
  ios::sync_with_stdio(false);
  pot[0] = 1;
  for (int i = 1; i < N; i++) pot[i] = pot[i - 1] * b % mod;
  cin >> str;
  prep(str, h);
  int m;
  cin >> m;
  vector<pair<int, int> > qs;
  for (int i = 0; i < m; i++) {
    string aux;
    cin >> aux;
    int l, r;
    cin >> l >> r;
    qs.push_back(pair<int, int>(l, r));
    pr(aux, ha[i]);
  }
  int ans = 0;
  set<int> seen;
  for (int l = 0; l < str.size(); l++)
    for (int r = l; r < str.size(); r++) {
      int hx = 0;
      for (int i = l; i <= r; i++) {
        hx = 1LL * hx * b % mod;
        hx += str[i] - 'a' + 1;
        hx %= mod;
      }
      if (seen.count(hx)) continue;
      seen.insert(hx);
      bool ok = 1;
      for (int i = 0; i < m; i++) {
        int rr = ha[i][hx];
        ok &= rr >= qs[i].first && rr <= qs[i].second;
      }
      ans += ok;
    }
  cout << ans << endl;
  return 0;
}
