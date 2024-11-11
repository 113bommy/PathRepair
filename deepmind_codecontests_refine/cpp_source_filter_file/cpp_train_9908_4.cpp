#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adl[200010];
vector<pair<pair<int, int>, int>> inp;
map<int, bool> cek;
map<int, int> conv;
long long ans[500][500];
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, ke;
  cin >> n >> m >> ke;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    inp.push_back(make_pair(make_pair(a, b), w));
  }
  sort(inp.begin(), inp.end(), cmp);
  int cnt = 0;
  for (int i = 0; i < min(ke, m); i++) {
    int a = inp[i].first.first, b = inp[i].first.second, w = inp[i].second;
    if (!cek[a]) {
      cek[a] = 1;
      conv[a] = cnt;
      cnt++;
    }
    if (!cek[b]) {
      cek[b] = 1;
      conv[b] = cnt;
      cnt++;
    }
  }
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++) {
      ans[i][j] = 1e18;
    }
  }
  for (int i = 0; i < min(ke, m); i++) {
    int a = inp[i].first.first, b = inp[i].first.second, w = inp[i].second;
    a = conv[a];
    b = conv[b];
    ans[a][b] = min(ans[a][b], (long long)w);
    ans[b][a] = min(ans[b][a], (long long)w);
  }
  for (int k = 0; k < cnt; k++) {
    for (int i = 0; i < cnt; i++) {
      for (int j = 0; j < cnt; j++) {
        ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
      }
    }
  }
  vector<long long> v;
  for (int i = 0; i < cnt; i++) {
    for (int j = i + 1; j < cnt; j++) {
      v.push_back(ans[i][j]);
    }
  }
  sort(v.begin(), v.end());
  cout << v[ke - 1] << '\n';
  return 0;
}
