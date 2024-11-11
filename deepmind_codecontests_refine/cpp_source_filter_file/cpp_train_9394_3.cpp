#include <bits/stdc++.h>
using namespace std;
string s = ".RYB";
const int N = 2005;
int con[N][2];
int rep[N];
bool sol[N], nonzero[N];
vector<bitset<N> > eqn;
void print(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << eqn[i][j];
    cout << " | " << eqn[i][m] << endl;
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    con[i][0] = 1;
    con[i][1] = 2;
  }
  while (m--) {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
      cin >> v[i];
      v[i]--;
    }
    if (s == "RY") {
      for (int x : v) swap(con[x][0], con[x][1]);
    } else if (s == "RB") {
      for (int x : v) con[x][1] ^= con[x][0];
    } else if (s == "YB") {
      for (int x : v) con[x][0] ^= con[x][1];
    } else {
      bitset<N> eq1, eq2;
      for (int x : v) {
        if (con[x][0] & 1) eq1[2 * x] = 1;
        if (con[x][0] & 2) eq1[2 * x + 1] = 1;
        if (con[x][1] & 1) eq2[2 * x] = 1;
        if (con[x][1] & 2) eq2[2 * x + 1] = 1;
      }
      string s;
      cin >> s;
      if (s == "R" || s == "B") eq1[2 * n] = 1;
      if (s == "Y" || s == "B") eq2[2 * n] = 1;
      eqn.push_back(eq1);
      eqn.push_back(eq2);
    }
  }
  int k = eqn.size();
  memset(rep, -1, sizeof rep);
  for (int row = 0; row < k; row++) {
    for (int j = 0; j < 2 * n; j++) {
      if (eqn[row][j] == 0) continue;
      if (rep[j] != -1)
        eqn[row] ^= eqn[rep[j]];
      else {
        rep[j] = row;
        nonzero[j] = true;
        break;
      }
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (rep[i] == -1) continue;
    for (int j = 0; j < 2 * n; j++)
      if (i != j && rep[j] != -1 && eqn[rep[i]][j] == 1)
        eqn[rep[i]] ^= eqn[rep[j]];
  }
  for (int i = 0; i < k; i++) {
    if (!nonzero[i] && eqn[i][2 * n]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int i = 0; i < 2 * n; i++) {
    if (rep[i] == -1)
      sol[i] = 0;
    else
      sol[i] = eqn[rep[i]][2 * n];
  }
  cout << "YES" << endl;
  for (int i = 0; i < 2 * n; i += 2) {
    int v = sol[i] | sol[i + 1] << 1;
    cout << s[v];
  }
}
