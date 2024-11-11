#include <bits/stdc++.h>
const int DEB = 0;
using namespace std;
const string S = "BERLAND";
map<string, int> _name;
map<int, string> rev;
int name(string s) {
  if (_name.count(s))
    ;
  else {
    int tmp = _name.size();
    _name[s] = tmp;
    rev[tmp] = s;
  }
  return _name[s];
}
const int N = 4;
pair<int, int> g[N][N];
struct T {
  int t, w, l;
  string name;
  T(int _t, int _w, int _l, string n) : t(_t), w(_w), l(_l), name(n) {}
};
bool operator<(const T &a, const T &b) {
  if (a.t != b.t) return a.t < b.t;
  int diffA = a.w - a.l;
  int diffB = b.w - b.l;
  if (diffA != diffB) return diffA < diffB;
  if (a.w != b.w) return a.w < b.w;
  return a.name > b.name;
}
bool solve(void) {
  int p[N];
  int win[N];
  int lose[N];
  fill(p, p + N, 0);
  fill(win, win + N, 0);
  fill(lose, lose + N, 0);
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (g[i][j].first == g[i][j].second) {
        p[i] += 1;
        p[j] += 1;
      } else if (g[i][j].first < g[i][j].second) {
        p[j] += 3;
      } else if (g[i][j].first > g[i][j].second) {
        p[i] += 3;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      win[i] += g[i][j].first;
      lose[i] += g[i][j].second;
    }
  }
  vector<T> v;
  for (int i = 0; i < N; ++i) {
    v.push_back(T(p[i], win[i], lose[i], rev[i]));
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  if (DEB) {
    for (int i = 0; i < v.size(); ++i) {
      cout << v[i].t << ' ' << v[i].w << ' ' << v[i].l << " : " << v[i].name
           << endl;
    }
  }
  return v[0].name == S || v[1].name == S;
}
pair<int, int> better(pair<int, int> a, pair<int, int> b) {
  if (a.first == -1) return b;
  int diffA = a.first - a.second;
  int diffB = b.first - b.second;
  if (diffA != diffB) return diffA < diffB ? a : b;
  return a.second < b.second ? a : b;
}
int main(int argc, char *argv[]) {
  while (true) {
    _name.clear();
    rev.clear();
    fill(&g[0][0], &g[N - 1][N], make_pair(-1, -1));
    for (int i = 0; i < 5; ++i) {
      string a, b;
      char c;
      int n, m;
      cin >> a >> b >> n >> c >> m;
      g[name(a)][name(b)] = make_pair(n, m);
      g[name(b)][name(a)] = make_pair(m, n);
    }
    if (_name.size() != 4) break;
    int i = name(S);
    pair<int, int> res = make_pair(-1, -1);
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      if (g[i][j].first == -1) {
        for (int x = 0; x <= 100; ++x) {
          for (int y = 0; y < x; ++y) {
            if (x > y)
              ;
            else
              continue;
            g[i][j] = make_pair(x, y);
            g[j][i] = make_pair(y, x);
            if (DEB) cout << x << ' ' << y << endl;
            if (solve()) res = better(res, make_pair(x, y));
          }
        }
      } else {
        continue;
      };
      break;
    }
    if (res.first != -1)
      cout << res.first << ":" << res.second << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
