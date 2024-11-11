#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int mat[maxn][maxn], f, t = 2, r, k;
vector<int> deg, q, adj[maxn];
int com(int x, int y) {
  int s = 1;
  for (int i = 0; i < y; i++) s *= x - i;
  for (int i = 1; i <= y; i++) s /= i;
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> k;
  while (com(t + 1, 3) <= k) t++;
  r = k - com(t, 3);
  f = t;
  while (r != 0) {
    f++;
    int s = 1;
    while (com(s + 1, 2) <= r) s++;
    r -= com(s, 2);
    q.push_back(f);
    deg.push_back(s);
  }
  for (int i = 1; i <= t; i++)
    for (int j = 1; j <= t; j++)
      if (i != j) mat[i][j] = 1;
  for (int i = 0; i < q.size(); i++)
    for (int j = 1; j <= deg[i]; j++) {
      mat[q[i]][j] = 1;
      mat[j][q[i]] = 1;
    }
  cout << t + q.size() << endl;
  for (int i = 1; i <= t + q.size(); i++) {
    for (int j = 1; j <= t + q.size(); j++) cout << mat[i][j] << " ";
    cout << endl;
  }
  return 0;
}
