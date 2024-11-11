#include <bits/stdc++.h>
using namespace std;
int n, m, cl[1050][1050], cq[1050][1050], ans;
int a[1050][1050], b[1050][1050], c[1050][1050], d[1050][1050];
char gr[1050][1050];
vector<int> x, y, s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> gr[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (gr[i][j] != '*') continue;
      b[i][j]++;
      b[i][j] += b[i][j - 1];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = m - 1; j >= 0; j--) {
      if (gr[i][j] != '*') continue;
      a[i][j]++;
      a[i][j] += a[i][j + 1];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (gr[j][i] != '*') continue;
      c[j][i]++;
      c[j][i] += c[j - 1][i];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (gr[j][i] != '*') continue;
      d[j][i]++;
      d[j][i] += d[j + 1][i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int aa = a[i][j], bb = b[i][j], cc = c[i][j], dd = d[i][j];
      aa = min(min(aa, bb), min(cc, dd)) - 1;
      if (aa <= 0) continue;
      cl[i][j - aa]++;
      cq[i - aa][j]++;
      cl[i][j + aa + 1]--;
      cq[i + aa + 1][j]--;
      x.push_back(i);
      y.push_back(j);
      s.push_back(aa);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 || j == 0) continue;
      cl[i][j] += cl[i][j - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) continue;
      cq[j][i] += cq[j - 1][i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cq[i][j] + cl[i][j] == 0 && gr[i][j] == '*') {
        cout << -1;
        return 0;
      }
    }
  }
  cout << s.size() << endl;
  for (int i = 0; i < s.size(); i++)
    cout << x[i] + 1 << ' ' << y[i] + 1 << ' ' << s[i] << endl;
  ;
}
