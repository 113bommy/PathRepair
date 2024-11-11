#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int matrix[N][N], marker[N][N];
int n, m;
bool f(int x) {
  for (int i = 0; i < N; i++) fill(marker[i], marker[i] + N, 0);
  vector<int> indeces;
  indeces.reserve(10000);
  for (int i = 0; i < n; i++) {
    indeces.clear();
    for (int j = 0; j < m; j++) {
      if (matrix[i][j] >= x) indeces.push_back(j);
    }
    for (int j = 0; j < indeces.size(); j++) {
      for (int k = j + 1; k < indeces.size(); k++) {
        int a = indeces[j], b = indeces[k];
        if (marker[a][b]) return true;
        marker[a][b] = true;
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> matrix[i][j];
  int left = 0, right = (int)1e9 + 10;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (f(mid))
      left = mid;
    else
      right = mid;
  }
  cout << left << endl;
}
