#include <bits/stdc++.h>
using namespace std;
const long long INF = 3000000000000;
int per[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
                 {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
vector<vector<int> > P(8, vector<int>(3));
vector<vector<int> > p(8, vector<int>(3));
long long Ska(vector<int>& a, vector<int>& b, vector<int>& c) {
  long long ska = 0;
  for (int i = 0; i < 3; ++i)
    ska += (long long)(b[i] - a[i]) * (long long)(c[i] - a[i]);
  return ska;
}
long long Dl(vector<int>& a, vector<int>& b) {
  long long d = 0;
  for (int i = 0; i < 3; ++i)
    d += (long long)(a[i] - b[i]) * (long long)(a[i] - b[i]);
  return d;
}
void Spr(vector<int>& c) {
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 3; ++j) p[i][j] = P[i][per[c[i]][j]];
  long long D = INF;
  for (int i = 0; i < 8; ++i)
    for (int j = i + 1; j < 8; ++j) D = min(D, Dl(p[i], p[j]));
  for (int i = 0; i < 8; ++i) {
    vector<int> nr;
    for (int j = 0; j < 8; ++j)
      if (Dl(p[i], p[j]) == D) nr.push_back(j);
    if (!(nr.size() == 3 && Ska(p[i], p[nr[0]], p[nr[1]]) == 0 &&
          Ska(p[i], p[nr[0]], p[nr[2]]) == 0 &&
          Ska(p[i], p[nr[1]], p[nr[2]]) == 0))
      return;
  }
  cout << "YES" << endl;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 3; ++j) cout << p[i][j] << " ";
    cout << endl;
  }
  exit(0);
}
void gen(vector<int>& a, int nr, int x) {
  a[nr] = x;
  if (nr == 7) {
    Spr(a);
    return;
  }
  for (int i = 0; i < 6; ++i) gen(a, nr + 1, i);
}
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 3; ++j) cin >> P[i][j];
  vector<int> x(8);
  for (int i = 0; i < 6; ++i) gen(x, 0, i);
  cout << "NO";
  return 0;
}
