#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const long long INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
int n;
vector<int> B, skill, L, R;
int b, g;
string buf;
struct P {
  int x, y, dif;
  P() {}
  P(int a, int b, int c) {
    x = a;
    y = b;
    dif = c;
  }
};
bool operator<(const P& a, const P& b) {
  return a.dif < b.dif || a.dif == b.dif && a.x < b.x;
}
set<P> S;
int main() {
  g = 0, b = 0;
  cin >> n;
  cin >> buf;
  B.resize(n);
  L.resize(n);
  R.resize(n);
  skill.resize(n);
  for (int i = 0; i < n; ++i) {
    B[i] = buf[i] == 'B';
    b += B[i];
    L[i] = i - 1, R[i] = i + 1;
  }
  g = n - b;
  for (int i = 0; i < n; ++i) cin >> skill[i];
  for (int i = 0; i < n - 1; ++i) {
    if (B[i] != B[i + 1]) {
      P add;
      add.x = i;
      add.y = i + 1;
      add.dif = abs(skill[i] - skill[i + 1]);
      S.insert(add);
    }
  }
  cout << min(g, b) << endl;
  for (int i = 0; i < min(g, b); ++i) {
    P cur = *S.begin();
    cout << cur.x + 1 << " " << cur.y + 1 << endl;
    S.erase(cur);
    if (L[cur.x] != -1) {
      if (B[cur.x] != B[L[cur.x]])
        S.erase(P(L[cur.x], cur.x, abs(skill[L[cur.x]] - skill[cur.x])));
      R[L[cur.x]] = R[cur.y];
    }
    if (R[cur.y] != n) {
      if (B[cur.y] != B[R[cur.y]])
        S.erase(P(cur.y, R[cur.y], abs(skill[R[cur.y]] - skill[cur.y])));
      L[R[cur.y]] = L[cur.x];
    }
    if (L[cur.x] != -1 && R[cur.y] != n && B[L[cur.x]] != B[R[cur.y]])
      S.insert(P(L[cur.x], R[cur.y], skill[L[cur.x]] - skill[R[cur.y]]));
  }
  return 0;
}
