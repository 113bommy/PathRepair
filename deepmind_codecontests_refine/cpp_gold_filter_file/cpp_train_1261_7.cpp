#include <bits/stdc++.h>
using namespace std;
char mat[2002][2002];
int N[1002][1002];
int second[1002][1002];
int E[1002][1002];
int W[1002][1002];
char d[200002];
int v[100102];
int main() {
  int n, m, q;
  vector<pair<int, int> > origins;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", mat[i]);
    for (int j = 0; j < m; j++) {
      if (mat[i][j] >= 'A' && mat[i][j] <= 'Z')
        origins.push_back(pair<int, int>(i, j));
    }
  }
  for (int i = 0; i < n; i++) {
    int last = -1;
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') last = j;
      W[i][j] = last;
    }
    last = m;
    for (int j = m - 1; j >= 0; j--) {
      if (mat[i][j] == '#') last = j;
      E[i][j] = last;
    }
  }
  for (int j = 0; j < m; j++) {
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (mat[i][j] == '#') last = i;
      N[i][j] = last;
    }
    last = n;
    for (int i = n - 1; i >= 0; i--) {
      if (mat[i][j] == '#') last = i;
      second[i][j] = last;
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) scanf(" %c%d", &d[i], &v[i]);
  set<char> st;
  for (auto x : origins) {
    int i = x.first, j = x.second;
    char aux = mat[i][j];
    bool check = 1;
    for (int k = 0; k < q; k++) {
      if (d[k] == 'W') {
        if (W[i][j] >= j - v[k]) {
          check = 0;
          break;
        }
        j -= v[k];
      }
      if (d[k] == 'E') {
        if (E[i][j] <= j + v[k]) {
          check = 0;
          break;
        }
        j += v[k];
      }
      if (d[k] == 'S') {
        if (second[i][j] <= i + v[k]) {
          check = 0;
          break;
        }
        i += v[k];
      }
      if (d[k] == 'N') {
        if (N[i][j] >= i - v[k]) {
          check = 0;
          break;
        }
        i -= v[k];
      }
      if (i < 0 || i >= n || j < 0 || j >= m)
        cout << "i"
             << " = " << i << " --- "
             << "j"
             << " = " << j << endl;
    }
    if (check) st.insert(aux);
  }
  for (auto x : st) printf("%c", x);
  if (st.empty()) puts("no solution");
}
