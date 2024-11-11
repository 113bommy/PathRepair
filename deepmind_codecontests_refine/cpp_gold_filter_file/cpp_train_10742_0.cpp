#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, z;
  int i;
  bool used;
  bool operator<(pt const &p) const {
    return x < p.x || (x == p.x && (y < p.y || (y == p.y && z < p.z)));
  }
};
bool check(vector<pair<int, int>> &ans, vector<pt> const &A) {
  vector<pt> a(A);
  for (auto E : ans) {
    int i = E.first;
    int j = E.second;
    a[i].used = 1;
    a[j].used = 1;
    int x = min(a[i].x, a[j].x);
    int X = max(a[i].x, a[j].x);
    int y = min(a[i].y, a[j].y);
    int Y = max(a[i].y, a[j].y);
    int z = min(a[i].z, a[j].z);
    int Z = max(a[i].z, a[j].z);
    for (auto e : a) {
      if (!e.used && x <= e.x && e.x <= X && y <= e.y && e.y <= Y && z <= e.x &&
          e.x <= Z) {
        return false;
      }
    }
  }
  return true;
}
void solve(vector<pt> const &A) {
  vector<pt> a(A);
  int n = a.size();
  map<pair<int, int>, vector<pt>> m;
  for (int i = 0; i < n; i++) {
    m[{a[i].x, a[i].y}].push_back(a[i]);
  }
  vector<pair<int, int>> ans;
  a.clear();
  for (auto e : m) {
    vector<pt> p = e.second;
    sort((p).begin(), (p).end());
    while (p.size() > 1) {
      ans.push_back({p[p.size() - 1].i, p[p.size() - 2].i});
      p.pop_back();
      p.pop_back();
    }
    if (p.size()) {
      a.push_back(p.back());
    }
  }
  map<int, vector<pt>> mm;
  for (auto e : a) mm[e.x].push_back(e);
  a.clear();
  for (auto e : mm) {
    vector<pt> p = e.second;
    sort((p).begin(), (p).end());
    while (p.size() > 1) {
      ans.push_back({p[p.size() - 1].i, p[p.size() - 2].i});
      p.pop_back();
      p.pop_back();
    }
    if (p.size()) {
      a.push_back(p.back());
    }
  }
  sort((a).begin(), (a).end());
  for (int i = 0; i < a.size(); i += 2) {
    ans.push_back({a[i].i, a[i + 1].i});
  }
  for (auto e : ans) cout << e.first + 1 << ' ' << e.second + 1 << "\n";
}
int main() {
  int n = 10;
  const int maxC = 10;
  const int it = 1000;
  cin >> n;
  vector<pt> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
    a[i].i = i;
  }
  solve(a);
  return 0;
}
