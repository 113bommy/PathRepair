#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 2e5 + 10;
const int MOD = 1e9 + 7;
int n, m, a, b, c;
int v[M][4];
int x[N];
int col[3];
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (m); i++) {
    cin >> a >> b >> c;
    v[i][0] = a;
    v[i][1] = b;
    v[i][2] = c;
  }
  for (int i = (1); i <= (m); i++) {
    int a = v[i][0];
    int b = v[i][1];
    int c = v[i][2];
    if (x[a] && x[b] && x[c]) continue;
    for (int d = (1); d <= (3); d++) col[d] = 0;
    col[x[a]] = col[x[b]] = col[x[c]] = 1;
    vector<int> z;
    for (int d = (1); d <= (3); d++) {
      if (col[d] == 0) z.push_back(d);
    }
    int l = 0;
    for (int j = (0); j <= (2); j++) {
      int a = v[i][j];
      if (x[a] == 0) {
        x[a] = z[l++];
      }
    }
  }
  for (int i = (1); i <= (n); i++) cout << x[i] << " ";
  cout << endl;
  return 0;
}
