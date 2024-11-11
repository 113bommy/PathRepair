#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
bool debug = 1;
const int N = 1e5 + 10;
int n, m;
set<int> s[100];
vector<vector<int>> v;
bool trans = 0;
bool ok(int i, int j) { return i >= 0 and i < n and j >= 0 and j < m; }
bool checar = 1;
void check() {
  if (checar) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ok(i + 1, j)) {
          if (s[v[i][j]].find(v[i + 1][j]) != s[v[i][j]].end()) return;
        }
        if (ok(i - 1, j)) {
          if (s[v[i][j]].find(v[i - 1][j]) != s[v[i][j]].end()) return;
        }
        if (ok(i, j - 1)) {
          if (s[v[i][j]].find(v[i][j - 1]) != s[v[i][j]].end()) return;
        }
        if (ok(i, j + 1)) {
          if (s[v[i][j]].find(v[i][j + 1]) != s[v[i][j]].end()) return;
        }
      }
    }
  }
  cout << "YES" << endl;
  if (!trans)
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", v[i][j]);
      }
      printf("\n");
    }
  else {
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        printf("%d ", v[i][j]);
      }
      printf("\n");
    }
  }
  exit(0);
}
int main() {
  cin >> n >> m;
  if (n * m <= 9) {
    int cur = 1;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = cur++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ok(i + 1, j)) {
          s[v[i][j]].insert(v[i + 1][j]);
        }
        if (ok(i - 1, j)) {
          s[v[i][j]].insert(v[i - 1][j]);
        }
        if (ok(i, j - 1)) {
          s[v[i][j]].insert(v[i][j - 1]);
        }
        if (ok(i, j + 1)) {
          s[v[i][j]].insert(v[i][j + 1]);
        }
      }
    }
    vector<int> p;
    for (int i = 1; i <= n * m; i++) {
      p.push_back(i);
    }
    do {
      int id = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          v[i][j] = p[id++];
        }
      }
      check();
    } while (next_permutation(p.begin(), p.end()));
    cout << "NO" << endl;
  } else if (max(n, m) >= 8) {
    checar = 0;
    if (m > n) swap(n, m), trans = 1;
    v.resize(n, vector<int>(m));
    int cur = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = cur++;
      }
    }
    vector<vector<int>> vorig = v;
    if (debug)
      cout << "n"
           << " = " << (n) << endl;
    if (debug)
      cout << "m"
           << " = " << (m) << endl;
    int nc = n - (n % 4);
    for (int i = 0; i < nc; i++) {
      int cur = 0;
      if (i % 2 == 0) cur = 1;
      for (int j = 0; j < m; j++) {
        if (j == cur) {
          cur += 2;
          v[i][j] = vorig[(i + 4) % nc][j];
        }
      }
    }
    if (debug) cout << "m1" << endl;
    for (int i = nc; i <= n - 1; i++) {
      int cur = 0;
      if (i % 2 == 0) cur = 1;
      for (int j = 0; j < m; j++) {
        if (j == cur) {
          cur += 2;
          v[i][j] = vorig[i][j];
          swap(v[i][j], v[i - nc][j]);
        }
      }
    }
    if (debug) cout << "m2" << endl;
    check();
    cout << "NO" << endl;
  } else {
    int cur = 1;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v[i][j] = cur++;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ok(i + 1, j)) {
          s[v[i][j]].insert(v[i + 1][j]);
        }
        if (ok(i - 1, j)) {
          s[v[i][j]].insert(v[i - 1][j]);
        }
        if (ok(i, j - 1)) {
          s[v[i][j]].insert(v[i][j - 1]);
        }
        if (ok(i, j + 1)) {
          s[v[i][j]].insert(v[i][j + 1]);
        }
      }
    }
    vector<int> p;
    for (int i = 1; i <= n * m; i++) {
      p.push_back(i);
    }
    int iter = 0;
    do {
      random_shuffle(p.begin(), p.end());
      int id = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          v[i][j] = p[id++];
        }
      }
      check();
    } while (1);
  }
  return 0;
}
