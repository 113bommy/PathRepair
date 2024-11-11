#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, vector<int>> vertical, horizontal;
vector<array<int, 4>> vseg, hseg;
vector<int> graph[1000007];
int match[1000007];
int odw[1000007];
int taken[1000007];
int visited[1000007];
set<pair<int, int>> in;
bool intersect(array<int, 4> &a, array<int, 4> &b) {
  if (a[0] > b[2] or a[0] < b[0]) return false;
  if (b[1] > a[3] or b[1] < a[1]) return false;
  if (in.find({a[0], b[1]}) != in.end()) return false;
  return true;
}
bool dfs(int v) {
  if (odw[v] != -1) return false;
  odw[v] = 1;
  for (auto &i : graph[v]) {
    if (match[i] == -1 or dfs(match[i])) {
      match[i] = v;
      match[v] = i;
      return true;
    }
  }
  return false;
}
vector<array<int, 4>> ansv, ansh;
void go(int v) {
  if (visited[v]) return;
  visited[v] = 1;
  for (auto &i : graph[v]) {
    visited[i] = 1;
    if (match[i] != -1) go(match[i]);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    vertical[a].push_back(b);
    horizontal[b].push_back(a);
    in.insert({a, b});
  }
  for (auto &i : vertical) {
    sort(i.second.begin(), i.second.end());
    for (int j = 1; j < i.second.size(); ++j) {
      vseg.push_back({i.first, i.second[j - 1], i.first, i.second[j]});
    }
  }
  for (auto &i : horizontal) {
    sort(i.second.begin(), i.second.end());
    for (int j = 1; j < i.second.size(); ++j) {
      hseg.push_back({i.second[j - 1], i.first, i.second[j], i.first});
    }
  }
  for (int i = 0; i < vseg.size() + hseg.size(); ++i) {
    match[i] = -1;
    odw[i] = -1;
    taken[i] = 0;
  }
  for (int i = 0; i < vseg.size(); ++i) {
    for (int j = 0; j < hseg.size(); ++j) {
      if (intersect(vseg[i], hseg[j])) {
        graph[i].push_back(j + vseg.size());
      }
    }
  }
  bool change = false;
  do {
    change = false;
    for (int i = 0; i < vseg.size() + hseg.size(); ++i) odw[i] = -1;
    for (int i = 0; i < vseg.size(); ++i) {
      if (match[i] == -1 and dfs(i)) {
        change = true;
      }
    }
  } while (change);
  for (int i = 0; i < vseg.size() + hseg.size(); ++i) {
    taken[i] = visited[i] = 0;
  }
  for (int i = 0; i < vseg.size(); ++i) {
    if (!visited[i] and match[i] == -1) {
      go(i);
    }
  }
  for (int i = 0; i < vseg.size(); ++i)
    if (!visited[i]) taken[i] = 1;
  for (int i = 0; i < hseg.size(); ++i)
    if (visited[vseg.size() + i]) taken[i + vseg.size()] = 1;
  set<array<int, 4>> must;
  vector<array<int, 4>> oo[2];
  for (int i = 0; i < vseg.size(); ++i) {
    if (!taken[i]) {
      must.insert(vseg[i]);
      oo[0].push_back(vseg[i]);
    }
  }
  for (int i = 0; i < hseg.size(); ++i) {
    if (!taken[i + vseg.size()]) {
      must.insert(hseg[i]);
      oo[1].push_back(hseg[i]);
    }
  }
  for (auto &i : oo[0])
    for (auto &x : oo[1])
      if (intersect(i, x)) {
        cout << "dupa "
             << "\n";
        exit(0);
      }
  for (auto &i : vertical) {
    for (int j = 0; j < i.second.size(); ++j) {
      if (j < i.second.size() - 1) {
        int p = j;
        while (p + 1 < i.second.size() and
               must.find({i.first, i.second[p], i.first, i.second[p + 1]}) !=
                   must.end())
          p++;
        ansv.push_back({i.first, i.second[j], i.first, i.second[p]});
        j = p;
      } else {
        ansv.push_back({i.first, i.second[j], i.first, i.second[j]});
      }
    }
  }
  for (auto &i : horizontal) {
    for (int j = 0; j < i.second.size(); ++j) {
      if (j < i.second.size() - 1) {
        int p = j;
        while (p + 1 < i.second.size() and
               must.find({i.second[p], i.first, i.second[p + 1], i.first}) !=
                   must.end())
          p++;
        ansh.push_back({i.second[j], i.first, i.second[p], i.first});
        j = p;
      } else {
        ansh.push_back({i.second[j], i.first, i.second[j], i.first});
      }
    }
  }
  cout << ansh.size() << "\n";
  for (auto &i : ansh) {
    cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << "\n";
  }
  cout << ansv.size() << "\n";
  for (auto &i : ansv) {
    cout << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << "\n";
  }
}
