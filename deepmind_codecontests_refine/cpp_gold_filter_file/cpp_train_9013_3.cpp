#include <bits/stdc++.h>
using namespace std;
class color_ice_cream : public pair<bitset<500000>, bitset<500000> > {
  int n, m, last_used_color, *color;
  vector<int> *ice_cream, *neighbor;
  int read_int() {
    int x;
    scanf("%i", &x);
    return x;
  }
  int write_int(const int x) { return printf("%i", x); }
  int endline() { return printf("\n"); }
  int space() { return printf(" "); }

 public:
  color_ice_cream()
      : n(read_int()),
        m(read_int()),
        last_used_color(-1),
        color(new int[m]),
        ice_cream(new vector<int>[n]),
        neighbor(new vector<int>[n]) {
    for (int i = 0; i < n; i++) {
      int k = read_int();
      for (int j = 0; j < k; j++) ice_cream[i].push_back(read_int() - 1);
    }
    for (int i = 1; i < n; i++) {
      int u = read_int() - 1, v = read_int() - 1;
      neighbor[v].push_back(u);
      neighbor[u].push_back(v);
    }
    for (int i = 0; i < m; i++) color[i] = -1;
  }
  void solve(const int v = 0) {
    first.set(v);
    int j = -1, k = ice_cream[v].size(), l;
    for (int i = 0; i < k; i++)
      if ((l = color[ice_cream[v][i]]) != -1) second.set(l);
    for (int i = 0; i < k; i++)
      if (color[l = ice_cream[v][i]] == -1) {
        for (j++; second[j]; j++)
          ;
        second.set(j);
        color[l] = j;
      }
    second.reset();
    if (j > last_used_color) last_used_color = j;
    for (int c = neighbor[v].size(), i = 0; i < c; i++)
      if (!first[l = neighbor[v][i]]) solve(l);
  }
  void write_result() {
    write_int(max(last_used_color, 0) + 1), endline();
    for (int i = 0; i < m; i++) write_int(max(color[i], 0) + 1), space();
  }
};
int main() {
  color_ice_cream problem;
  problem.solve();
  problem.write_result();
}
