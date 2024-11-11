#include <bits/stdc++.h>
using namespace std;
const int Nmax = 110;
int n, k, st, fi, res;
string s1, s2;
int c[Nmax][Nmax], f[Nmax][Nmax], w[Nmax][Nmax];
int d[Nmax], t[Nmax];
bool inq[Nmax];
int stt(char x) {
  if ('a' <= x && x < 'z') return x - 'a' + 1;
  return x - 'A' + 27;
}
bool findpath() {
  queue<int> q;
  memset(inq, false, sizeof(inq));
  memset(t, 0, sizeof(t));
  for (int i = 1; i <= fi; ++i) d[i] = 1e9;
  q.push(st);
  inq[st] = false;
  d[st] = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    inq[x] = false;
    for (int y = 1; y <= fi; ++y)
      if (f[x][y] < c[x][y] && d[y] > d[x] + w[x][y]) {
        d[y] = d[x] + w[x][y];
        t[y] = x;
        if (!inq[y]) {
          q.push(y);
          inq[y] = true;
        }
      }
  }
  return d[fi] != 1e9;
}
void incflow() {
  int x = fi;
  while (x != st) {
    f[t[x]][x]++;
    f[x][t[x]]--;
    res -= w[t[x]][x];
    x = t[x];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  cin >> s1 >> s2;
  memset(c, 0, sizeof(c));
  memset(f, 0, sizeof(f));
  memset(w, 0, sizeof(w));
  for (int i = 0; i < n; ++i) w[stt(s1[i])][k + stt(s2[i])]--;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j) {
      c[i][k + j] = 1;
      w[k + j][i] = -w[i][k + j];
    }
  st = 2 * k + 1;
  fi = 2 * k + 2;
  for (int i = 1; i <= k; ++i) c[st][i] = c[k + i][fi] = 1;
  res = 0;
  for (int i = 1; i <= k; ++i) {
    findpath();
    incflow();
  }
  cout << res << endl;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j)
      if (f[i][k + j] > 0) {
        char c;
        if (j <= 26)
          c = 'a' + j - 1;
        else
          c = 'A' + j - 27;
        cout << c;
      }
}
