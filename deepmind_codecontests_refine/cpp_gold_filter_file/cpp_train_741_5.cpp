#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
vector<long long> v[200001];
long long vis[200001], color[200001];
vector<pair<long long, long long>> edge;
int main() {
  long long n, m;
  cin >> n >> m;
  while (m--) {
    long long a, b;
    cin >> a >> b;
    edge.push_back(make_pair(a, b));
    v[a].push_back(b);
    v[b].push_back(a);
  }
  queue<long long> q;
  q.push(1);
  color[1] = 1;
  vis[1] = 1;
  while (!q.empty()) {
    long long a = q.front();
    q.pop();
    for (auto i = v[a].begin(); i != v[a].end(); i++) {
      if (!vis[*i]) {
        if (color[a] == 1)
          color[*i] = 2;
        else
          color[*i] = 1;
        q.push(*i);
        vis[*i] = 1;
      } else if (color[a] == color[*i]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (auto i = edge.begin(); i != edge.end(); i++) {
    if (color[(i->first)] == 1)
      cout << "0";
    else
      cout << "1";
  }
}
