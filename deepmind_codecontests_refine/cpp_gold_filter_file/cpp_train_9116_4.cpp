#include <bits/stdc++.h>
using namespace std;
template <typename T>
void print(vector<T> s) {
  for (int i = 0; i < s.size(); i++) cout << s[i] << "";
  cout << "\n";
}
const int INF = 1e9 + 7;
const int MAX_N = 1e5;
vector<vector<pair<int, int> > > s;
vector<int> color;
vector<int> dist;
vector<vector<int> > cnt;
vector<int> result;
vector<vector<int> > used;
vector<int> sizee;
void dfs(int v) {
  color[v] = 1;
  for (pair<int, int> u : s[v]) {
    if (color[u.first] == 0) {
      cnt[v][u.second]++;
      dist[u.first] = dist[v] + 1;
      dfs(u.first);
      for (int j = 0; j < 26; j++) {
        if (cnt[u.first][j] > 0) used[v][j] = 1;
        sizee[v] += cnt[u.first][j];
      }
      result[dist[v]]++;
    }
  }
  int len = 0;
  for (int i = 0; i < 26; i++) len += used[v][i];
  result[dist[v]] += sizee[v] - len;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<string, int> mapa;
  vector<vector<int> > s;
  vector<string> lst(n);
  for (int i = 0; i < n; i++) {
    string a, b, c, s1, s2;
    cin >> a >> s1 >> b;
    mapa[a] = i;
    if (b[0] == '0' || b[0] == '1') {
      lst[i] = b;
      s.push_back({0, -1, 0});
      continue;
    }
    cin >> s2 >> c;
    int b1;
    if (b == "?")
      b1 = -1;
    else
      b1 = mapa[b];
    int c1;
    if (c == "?")
      c1 = -1;
    else
      c1 = mapa[c];
    if (s2 == "XOR") s.push_back({b1, 0, c1});
    if (s2 == "OR") s.push_back({b1, 1, c1});
    if (s2 == "AND") s.push_back({b1, 2, c1});
  }
  vector<bool> mini;
  vector<bool> maxi;
  vector<int> lst1(n);
  vector<int> lst2(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (s[j][1] == -1) {
        lst1[j] = lst[j][i] - '0';
        continue;
      }
      int a, b;
      if (s[j][0] == -1)
        a = 0;
      else
        a = lst1[s[j][0]];
      if (s[j][2] == -1)
        b = 0;
      else
        b = lst1[s[j][2]];
      if (s[j][1] == 0) lst1[j] = a ^ b;
      if (s[j][1] == 1) lst1[j] = a | b;
      if (s[j][1] == 2) lst1[j] = a & b;
    }
    for (int j = 0; j < n; j++) {
      int a, b;
      if (s[j][1] == -1) {
        lst2[j] = lst[j][i] - '0';
        continue;
      }
      if (s[j][0] == -1)
        a = 1;
      else
        a = lst2[s[j][0]];
      if (s[j][2] == -1)
        b = 1;
      else
        b = lst2[s[j][2]];
      if (s[j][1] == 0) lst2[j] = a ^ b;
      if (s[j][1] == 1) lst2[j] = a | b;
      if (s[j][1] == 2) lst2[j] = a & b;
    }
    int summa1 = 0;
    int summa2 = 0;
    for (int j = 0; j < n; j++) {
      summa1 += lst1[j];
      summa2 += lst2[j];
    }
    if (summa1 == summa2) {
      mini.push_back(0);
      maxi.push_back(0);
      continue;
    }
    if (summa1 < summa2) {
      mini.push_back(0);
      maxi.push_back(1);
    } else {
      mini.push_back(1);
      maxi.push_back(0);
    }
  }
  print(mini);
  print(maxi);
  return 0;
}
