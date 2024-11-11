#include <bits/stdc++.h>
using namespace std;
int t[80][80], tav[80][80][80];
int volt[80] = {};
int s, e;
bool sortFunc(int &a, int &b) { return t[s][a] + t[a][e] < t[s][b] + t[b][e]; }
int Ertek(int n, int a, int b) {
  for (int i = 0; i < n; i++)
    if (volt[tav[a][b][i]] == 0) return t[a][tav[a][b][i]] + t[tav[a][b][i]][b];
  return -1e9 + 7;
}
int meg = 1e9 + 7;
int buffer[10] = {};
void Megold(int x, int n, int k, int m) {
  if (x == m) {
    int last = 0, temp = 0;
    for (int i = 0; i < m; i++) {
      temp += Ertek(n, last, buffer[i]);
      last = buffer[i];
    }
    if (k % 2 == 1)
      temp += Ertek(n, buffer[m - 1], 0);
    else
      temp += t[buffer[m - 1]][0];
    if (temp > 0) meg = min(meg, temp);
    return;
  }
  for (int i = 0; i < n; i++) {
    buffer[x] = i;
    volt[i]++;
    Megold(x + 1, n, k, m);
    volt[i]--;
  }
  return;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> t[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < n; l++) tav[i][j][l] = l;
      s = i;
      e = j;
      sort(tav[i][j], tav[i][j] + n, sortFunc);
    }
  }
  volt[0] = 1;
  Megold(0, n, k - 1, (k - 1) / 2);
  cout << meg << "\n";
  return 0;
}
