#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
struct Face {
  int cnt;
  int id;
};
bool operator<(const Face &a, const Face &b) { return a.cnt < b.cnt; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12) << fixed;
  cerr << setprecision(12) << fixed;
  int n;
  cin >> n;
  vector<Face> faces(n);
  for (int i = 0; i < n; ++i) {
    cin >> faces[i].cnt;
    faces[i].id = i;
  }
  sort((faces).begin(), (faces).end());
  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + faces[i].cnt - 2;
  }
  vector<vector<int>> res(n);
  vector<int> face;
  for (int i = 0; i < faces.back().cnt; ++i) {
    face.push_back(i);
  }
  res[faces.back().id] = face;
  int cnt = faces.back().cnt;
  faces.back().id = -1;
  set<pii> edges;
  for (int i = 0; i < (int)(face).size(); ++i) {
    int j = (i + 1 == (int)(face).size() ? 0 : i + 1);
    edges.insert({face[i], face[j]});
    edges.insert({face[j], face[i]});
  }
  while ((int)(faces).size() > 1) {
    int k = (int)(faces).size();
    swap(faces[k - 1], faces[k - 2]);
    int a = faces[k - 2].cnt;
    int b = faces[k - 1].cnt;
    assert(a >= b);
    int m = 1;
    while (a + b - 2 * m > pref[k - 2] + 3 && b - m > 1 &&
           (a != b || a - m > 2)) {
      ++m;
    }
    int u = 0, v = (int)(face).size() - m;
    vector<int> new_face;
    if (m != 1 && edges.count({face[u], face[v]})) {
      for (int i = (int)(face).size() - 1; i >= (int)(face).size() - m - 1;
           --i) {
        new_face.push_back(face[i]);
      }
      int tmp = face.back();
      for (int i = 0; i < m; ++i) {
        face.pop_back();
      }
      for (int i = 0; i < b - m - 1; ++i) {
        face.push_back(cnt);
        new_face.push_back(cnt++);
      }
      face.push_back(tmp);
    } else {
      new_face.push_back(face[0]);
      for (int i = (int)(face).size() - 1; i >= (int)(face).size() - m; --i) {
        new_face.push_back(face[i]);
      }
      for (int i = 0; i < m - 1; ++i) {
        face.pop_back();
      }
      for (int i = 0; i < b - m - 1; ++i) {
        face.push_back(cnt);
        new_face.push_back(cnt++);
      }
    }
    for (int i = 0; i < (int)(new_face).size(); ++i) {
      int j = (i + 1 == (int)(new_face).size() ? 0 : i + 1);
      edges.insert({new_face[i], new_face[j]});
      edges.insert({new_face[j], new_face[i]});
    }
    res[faces.back().id] = new_face;
    faces[k - 2].cnt = (int)(face).size();
    faces.pop_back();
  }
  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    for (int u : res[i]) {
      cout << u + 1 << " ";
    }
    cout << endl;
  }
}
