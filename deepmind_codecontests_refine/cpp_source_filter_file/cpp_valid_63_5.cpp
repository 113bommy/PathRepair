#include <bits/stdc++.h>
using namespace std;
struct UF {
  vector<int> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
void solve() {
  int N, m1, m2;
  cin >> N >> m1 >> m2;
  UF x(N), y(N);
  for (int i = 0; i < m1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    x.join(a, b);
  }
  for (int i = 0; i < m2; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    y.join(a, b);
  }
  int num = 0;
  vector<pair<int, int> > thing;
  for (int e = 0; e < N; e++) {
    for (int r = 0; r < N; r++) {
      if (x.sameSet(e, r) == false && y.sameSet(e, r) == false) {
        num++;
        x.join(e, r);
        y.join(e, r);
        thing.push_back({e, r});
      }
    }
  }
  cout << num << endl;
  for (int i = 0; i < num; i++)
    cout << thing[i].first << " " << thing[i].second << endl;
}
int main() {
  int T = 1;
  while (T--) solve();
}
