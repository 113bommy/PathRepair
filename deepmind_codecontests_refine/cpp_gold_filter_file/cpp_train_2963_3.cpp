#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
bool vis[100005];
int c = 0;
vector<pair<pair<int, int>, int> > dic;
vector<pair<int, int> > save;
int convert(string s) {
  int x = 0, y = s.size();
  for (int i = 0; i < y; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 'a' - 'A';
    }
    if (s[i] == 'r') x++;
  }
  if (mp.find(s) != mp.end()) return mp[s];
  mp[s] = ++c;
  dic.push_back({{x, y}, c});
  save.push_back({x, y});
  return c;
}
int m;
string s, t;
vector<int> v, vec[100001];
void dfs(int x, int source, pair<int, int> z) {
  vis[x] = true;
  z = min(z, save[source]);
  for (int i = 0; i < vec[x].size(); i++) {
    if (!vis[vec[x][i]]) {
      dfs(vec[x][i], source, z);
    }
  }
  save[x] = min(save[x], z);
}
bool sorter(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first == b.first.first) return a.first.second < b.first.second;
  return a.first.first < b.first.first;
}
int main() {
  scanf("%d", &m);
  v.push_back(0);
  dic.push_back({{0, 0}, 0});
  save.push_back({0, 0});
  for (int i = 0; i < m; i++) {
    cin >> s;
    v.push_back(convert(s));
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    vec[convert(t)].push_back(convert(s));
  }
  sort(dic.begin() + 1, dic.end(), sorter);
  for (int i = 1; i < c; i++) {
    if (!vis[dic[i].second]) {
      dfs(dic[i].second, dic[i].second, save[dic[i].second]);
    }
  }
  long long ans = 0, len = 0;
  for (int i = 1; i <= m; i++) {
    ans += save[v[i]].first;
    len += save[v[i]].second;
  }
  cout << ans << " " << len;
  return 0;
}
