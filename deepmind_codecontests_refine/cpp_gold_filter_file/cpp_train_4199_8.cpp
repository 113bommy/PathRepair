#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> v;
vector<pair<int, int> > p;
int total = 0;
int vistos;
int iini, jini;
int ifin, jfin;
void pruebabis(int i1, int j1, int i2, int j2) {
  if (i1 + 2 > i2) return;
  if (j1 + 2 > j2) return;
  for (int ii = i1; ii <= i2; ii++)
    if (v[ii][j1] == '.' or v[ii][j2] == '.') return;
  for (int jj = j1; jj <= j2; jj++)
    if (v[i1][jj] == '.' or v[i2][jj] == '.') return;
  int vistosbis = 0;
  for (int ii = i1; ii <= i2; ii++) {
    vistosbis += v[ii][j1] == '#';
    vistosbis += v[ii][j2] == '#';
  }
  for (int jj = j1 + 1; jj < j2; jj++) {
    vistosbis += v[i1][jj] == '#';
    vistosbis += v[i2][jj] == '#';
  }
  if (vistos + vistosbis == total) {
    cout << "YES" << endl;
    cout << iini + 1 << " " << jini + 1 << " " << ifin + 1 << " " << jfin + 1
         << endl;
    cout << i1 + 1 << " " << j1 + 1 << " " << i2 + 1 << " " << j2 + 1 << endl;
    exit(0);
  }
}
void prueba(int i, int j) {
  ifin = i;
  jfin = j;
  for (int ii = iini; ii <= i; ii++)
    if (v[ii][jini] != '#' or v[ii][j] != '#') return;
  for (int jj = jini; jj <= j; jj++)
    if (v[iini][jj] != '#' or v[i][jj] != '#') return;
  for (int ii = iini; ii <= i; ii++) v[ii][jini] = v[ii][j] = 'X';
  for (int jj = jini; jj <= j; jj++) v[iini][jj] = v[i][jj] = 'X';
  vistos = 2 * (i - iini + 1) + 2 * (j - jini + 1) - 4;
  if (vistos == total) {
    cout << "YES" << endl;
    cout << iini + 1 << " " << jini + 1 << " " << ifin + 1 << " " << jfin + 1
         << endl;
    cout << iini + 1 << " " << jini + 1 << " " << ifin + 1 << " " << jfin + 1
         << endl;
    exit(0);
  }
  int mini = n - 1;
  int minj = m - 1;
  int maxi = 0;
  int maxj = 0;
  for (int k = 0; k < int(p.size()); k++) {
    if (v[p[k].first][p[k].second] == '#') {
      mini = min(mini, p[k].first);
      minj = min(minj, p[k].second);
      maxi = max(maxi, p[k].first);
      maxj = max(maxj, p[k].second);
    }
  }
  int op1[2];
  op1[0] = mini;
  op1[1] = max(0, mini - 1);
  int op3[2];
  op3[0] = maxi;
  op3[1] = min(n - 1, maxi + 1);
  if (mini == maxi) {
    op1[1] = iini;
    op3[1] = ifin;
  }
  int op2[2];
  op2[0] = minj;
  op2[1] = max(0, minj - 1);
  int op4[2];
  op4[0] = maxj;
  op4[1] = min(m - 1, maxj + 1);
  if (minj == maxj) {
    op2[1] = jini;
    op4[1] = jfin;
  }
  for (int a1 = 0; a1 <= 1; a1++)
    for (int a2 = 0; a2 <= 1; a2++)
      for (int a3 = 0; a3 <= 1; a3++)
        for (int a4 = 0; a4 <= 1; a4++)
          pruebabis(op1[a1], op2[a2], op3[a3], op4[a4]);
  for (int ii = iini; ii <= i; ii++) v[ii][jini] = v[ii][j] = '#';
  for (int jj = jini; jj <= j; jj++) v[iini][jj] = v[i][jj] = '#';
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  v = vector<string>(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '#') {
        p.push_back(pair<int, int>(i, j));
        total++;
      }
    }
  }
  if (int(p.size()) == 0 or int(p.size()) > 4 * n + 4 * m) {
    cout << "NO" << endl;
    exit(0);
  }
  iini = jini = -1;
  for (int i = 0; i < n and iini == -1; i++) {
    for (int j = 0; j < m and iini == -1; j++) {
      if (v[i][j] == '#') {
        iini = i;
        jini = j;
      }
    }
  }
  for (int k = 0; k < int(p.size()); k++) {
    int i = p[k].first;
    int j = p[k].second;
    if (i >= iini + 2 and j >= jini + 2) prueba(i, j);
  }
  cout << "NO" << endl;
}
