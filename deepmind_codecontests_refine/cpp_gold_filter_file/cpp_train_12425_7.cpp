#include <bits/stdc++.h>
using namespace std;
vector<int> v[5001], A;
int x, y, n, m, i, j, k;
bool f[50001], F[50001], Fr[50001];
int go(int x) {
  f[x] = 1;
  int K = 1;
  for (int I = 0; I < v[x].size(); I++)
    if (!f[v[x][I]]) K += go(v[x][I]);
  return K;
}
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      f[j] = 0;
      F[j] = 0;
    }
    f[i] = 1;
    A.clear();
    for (j = 0; j < v[i].size(); j++) A.push_back(go(v[i][j]));
    F[0] = 1;
    for (j = 0; j < A.size(); j++)
      for (k = n; k >= 0; k--)
        if (F[k]) F[k + A[j]] = 1;
    for (j = 1; j <= n; j++) Fr[j] = (Fr[j] || F[j]);
  }
  k = 0;
  for (i = 1; i < n - 1; i++)
    if (Fr[i]) k++;
  cout << k << endl;
  for (i = 1; i < n - 1; i++)
    if (Fr[i]) printf("%d %d\n", i, n - i - 1);
}
