#include <bits/stdc++.h>
using namespace std;
const long long INF = 9223372036854775807;
const long long INFINT = 2147483647;
const int N = 1000006;
const int NN = 1006;
const int MOD = 1000000007;
void DIE(string s) {
  cout << s << "\n";
  exit(0);
}
void DIE(vector<int> &v) {
  for (int i = 0; i < int(v.size()); i++) cout << v[i] << ' ';
  cout << "\n";
  exit(0);
}
void DIE(vector<long long> &v) {
  for (int i = 0; i < int(v.size()); i++) cout << v[i] << ' ';
  cout << "\n";
  exit(0);
}
void DIE(int a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << "\n";
  exit(0);
}
void DIE(string a[], int n) {
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << "\n";
  exit(0);
}
void DIE(long long x) {
  cout << x << "\n";
  exit(0);
}
void DIE(int x) {
  cout << x << "\n";
  exit(0);
}
void YES() { DIE("YES"); }
void Yes() { DIE("Yes"); }
void yes() { DIE("yes"); }
void NO() { DIE("NO"); }
void No() { DIE("No"); }
void no() { DIE("no"); }
vector<pair<int, int> > g[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  vector<int> dist(n, INFINT);
  dist[s] = 0;
  set<pair<int, int> > ik;
  for (int i = 0; i < n; i++) ik.insert({dist[i], i});
  while (ik.size()) {
    pair<int, int> v = *ik.begin();
    ik.erase(v);
    for (pair<int, int> to : g[v.second]) {
      if (dist[to.first] > v.first + to.second) {
        ik.erase({dist[to.first], to.first});
        dist[to.first] = v.first + to.second;
        ik.insert({dist[to.first], to.first});
      }
    }
  }
  int l;
  cin >> l;
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (dist[i] == l) ans1++;
    if (dist[i] >= l) continue;
    for (pair<int, int> to : g[i]) {
      if (dist[i] + to.second < l) continue;
      if (to.second - l + dist[i] + dist[to.first] == l) {
        ans2++;
        if (0) cerr << "A " << i << ' ' << to.first << "\n";
      } else if (l < dist[to.first] + (to.second - l + dist[i])) {
        ans1++;
        if (0) cerr << "B " << i << ' ' << to.first << "\n";
      }
    }
  }
  cout << ans1 + ans2 / 2;
}
