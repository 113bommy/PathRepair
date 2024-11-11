#include <bits/stdc++.h>
using namespace std;
const int dydis = 2e5 + 10;
int kek = 0;
int n, m, d;
bool galima = 1;
int tevas[dydis];
vector<pair<int, int> > ans;
vector<pair<int, int> > edges;
vector<int> gr[dydis];
int findP(int a) {
  if (tevas[a] == a) return a;
  return tevas[a] = findP(tevas[a]);
}
void conn(int a, int b) {
  a = findP(a);
  b = findP(b);
  tevas[b] = a;
}
void nul() {
  for (int i = 0; i < dydis; i++) tevas[i] = i;
}
int main() {
  cin >> n >> m >> d;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);
    edges.push_back({a, b});
    gr[a].push_back(b);
    gr[b].push_back(a);
    if (a != 0 && b != 0) {
      conn(a, b);
    }
  }
  sort(edges.begin(), edges.end());
  for (auto x : gr[0]) {
    if (findP(x) != findP(0)) {
      conn(x, 0);
      ans.push_back({0, x});
      kek++;
    }
  }
  nul();
  for (auto x : ans) {
    conn(x.first, x.second);
  }
  for (auto x : edges) {
    if (findP(x.first) == findP(x.second)) {
      continue;
    }
    if (x.first == 0) {
      if (kek >= d) continue;
      kek++;
      conn(x.first, x.second);
    } else {
      conn(x.first, x.second);
    }
    ans.push_back(x);
  }
  if (kek != d) {
    cout << "NO";
  } else {
    cout << "YES\n";
    for (auto x : ans) {
      cout << x.first + 1 << " " << x.second + 1 << "\n";
    }
  }
  return 0;
}
