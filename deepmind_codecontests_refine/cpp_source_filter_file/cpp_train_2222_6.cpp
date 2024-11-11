#include <bits/stdc++.h>
using namespace std;
void flood(vector<string>& A, int r, int c) {
  if (r < 0 || c < 0 || r >= A.size() || c >= A[r].size() || A[r][c] != '#')
    return;
  A[r][c] = '.';
  flood(A, r + 1, c);
  flood(A, r, c + 1);
  flood(A, r - 1, c);
  flood(A, r, c - 1);
}
bool isConnected(vector<string> A) {
  int comp = 0;
  int v[51][51] = {};
  for (int i = 0; i < A.size(); i++)
    for (int j = 0; j < A[i].size(); j++)
      if (A[i][j] == '#') {
        comp++;
        flood(A, i, j);
      }
  return comp < 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> A(n);
  for (auto& s : A) cin >> s;
  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (A[i][j] == '#') {
        cnt++;
        A[i][j] = '.';
        if (!isConnected(A)) return cout << 1, 0;
        A[i][j] = '#';
      }
  if (cnt < 3)
    cout << -1;
  else
    cout << 2;
}
