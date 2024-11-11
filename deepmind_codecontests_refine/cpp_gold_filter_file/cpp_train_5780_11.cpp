#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
inline long long toll(string s) {
  long long v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
struct edge {
  int cost, in, i, u, v;
};
bool cmp(edge f, edge s) {
  if (f.cost == s.cost) {
    return f.in > s.in;
  }
  return f.cost < s.cost;
}
bool cmp2(edge f, edge s) { return f.i < s.i; }
bool done[100002];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<edge> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].cost >> v[i].in;
    v[i].i = i;
  }
  sort(v.begin(), v.end(), cmp);
  int needTo = 2;
  int u = 1;
  int vv = u + 2;
  for (int i = 0; i < m; i++) {
    if (!v[i].in) {
      u++;
      if (u == vv) {
        u = 2;
        vv++;
      }
      if (!done[vv]) {
        cout << -1 << endl;
        return 0;
      } else {
        v[i].u = u;
        v[i].v = vv;
      }
    } else {
      v[i].u = 1;
      v[i].v = needTo;
      done[needTo++] = 1;
    }
  }
  sort(v.begin(), v.end(), cmp2);
  for (int i = 0; i < m; i++) {
    cout << v[i].u << " " << v[i].v << "\n";
  }
  return 0;
}
