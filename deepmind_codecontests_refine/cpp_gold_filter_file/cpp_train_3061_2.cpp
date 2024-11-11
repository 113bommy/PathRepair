#include <bits/stdc++.h>
using namespace std;
const int MAX = 100 + 10;
int n, m;
int g[MAX][MAX];
vector<int> p[MAX][MAX];
int get(vector<int> &before, int kind) {
  int j;
  int now = 0, cc = before.size();
  for (; now < (int)before.size(); now++) {
    if (now + 1 == (int)before.size()) break;
    int a = before[now];
    int b = before[now + 1];
    if (g[a][b] != kind) return 0;
    vector<int> &nL = p[a][b];
    for ((j) = (0); (j) != ((int)nL.size()); ++(j)) {
      if (cc < (int)before.size()) {
        if (nL[j] == before[cc])
          cc++;
        else
          return 0;
      } else {
        while (j < (int)nL.size()) {
          before.push_back(nL[j++]);
          if ((int)before.size() > 2 * n) return 0;
        }
        cc = before.size();
        break;
      }
    }
  }
  return 1;
}
int check(int a, int b) {
  int i, j;
  vector<int> &L = p[a][b];
  int len = L.size();
  for ((i) = (0); (i) <= (len - 2); ++(i))
    if (L[i] == a && L[i + 1] == b) {
      vector<int> before, after;
      for (j = i; j >= 0; --j) before.push_back(L[j]);
      for (j = i + 1; j < len; ++j) after.push_back(L[j]);
      if (get(before, 2) && get(after, 1) &&
          (int)before.size() + (int)after.size() <= 2 * n) {
        reverse(before.begin(), before.end());
        cout << before.size() + after.size() << endl;
        for ((j) = (0); (j) != ((int)before.size()); ++(j))
          cout << before[j] << " ";
        for ((j) = (0); (j) != ((int)after.size()); ++(j))
          cout << after[j] << " ";
        return 1;
      }
    }
  return 0;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for ((i) = (1); (i) <= (m); ++(i)) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a][b] = 1;
    g[b][a] = 2;
    int k, first;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &first);
      p[a][b].push_back(first);
    }
    p[b][a] = p[a][b];
    reverse(p[b][a].begin(), p[b][a].end());
  }
  for ((i) = (1); (i) <= (n); ++(i))
    for ((j) = (1); (j) <= (n); ++(j))
      if (g[i][j] == 1 && check(i, j)) return 0;
  printf("%d\n", 0);
  return 0;
}
