#include <bits/stdc++.h>
using namespace std;
int getn() {
  int h;
  scanf("%d", &h);
  return h;
}
template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& par) {
  cout << "[" << par.first << ";" << par.second << "]";
  return out;
}
vector<vector<int> > mini;
int n;
int nacitaj(int i, int j) {
  mini[i][j] = getn();
  i = (i != n - 1 ? i + 1 : 0);
  j = (i != 0 ? j : j + 1);
  return (j != n ? nacitaj(i, j) : 1);
}
int floydwardshal(int i, int j, int l) {
  mini[l][j] = min(mini[l][j], mini[l][i] + mini[i][j]);
  i = (i != n - 1 ? i + 1 : 0);
  j = (i != 0 ? j : j + 1);
  j = (j >= n ? 0 : j);
  l = (i == 0 && j == 0 ? l + 1 : l);
  return (l != n ? floydwardshal(i, j, l) : 0);
}
int maxi(int i, int j) {
  int mx = mini[i][j];
  i = (i != n - 1 ? i + 1 : 0);
  j = (i != 0 ? j : j + 1);
  return (j != n ? max(maxi(i, j), mx) : mx);
}
int main() {
  n = getn();
  mini.resize(n, vector<int>(n, 0));
  nacitaj(0, 0);
  floydwardshal(0, 0, 0);
  cout << maxi(0, 0) << endl;
}
