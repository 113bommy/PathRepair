#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[1005][1005];
vector<int> frow[1005];
vector<int> fcol[1005];
vector<int> row[1005];
vector<int> col[1005];
bool bin(vector<int>& x, int v) {
  int ini = 0;
  int fin = x.size() - 1;
  while (ini < fin) {
    int mid = (ini + fin) / 2;
    if (x[mid] >= v)
      fin = mid;
    else
      ini = mid + 1;
  }
  return ini;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
      frow[i].push_back(a[i][j]);
      fcol[j].push_back(a[i][j]);
    }
  for (int i = 1; i <= N; i++) {
    sort(frow[i].begin(), frow[i].end());
    row[i].push_back(frow[i][0]);
    for (int j = 1; j < M; j++)
      if (frow[i][j] != frow[i][j - 1]) row[i].push_back(frow[i][j]);
  }
  for (int i = 1; i <= M; i++) {
    sort(fcol[i].begin(), fcol[i].end());
    col[i].push_back(fcol[i][0]);
    for (int j = 1; j < N; j++)
      if (fcol[i][j] != fcol[i][j - 1]) col[i].push_back(fcol[i][j]);
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int v = a[i][j];
      int p1 = bin(row[i], v);
      int p2 = bin(col[j], v);
      cout << max(p1, p2) +
                  max(row[i].size() - p1 - 1, col[j].size() - p2 - 1) + 1
           << (" \n"[j == M]);
    }
  return 0;
}
