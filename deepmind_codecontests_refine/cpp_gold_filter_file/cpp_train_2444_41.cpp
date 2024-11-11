#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
string arr[100];
int CO, RO;
int di[] = {0, 1, 0, -1};
int dj[] = {1, 0, -1, 0};
bool valid(int i, int j) {
  if (i != -1 && j != -1 && i != RO && j != CO) return 1;
  return 0;
}
bool DFS(int i, int j, int previ, int prevj) {
  if (vis[i][j]) return 1;
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int Newi = i + di[k], Newj = j + dj[k];
    if (valid(Newi, Newj) && (Newi != previ || Newj != prevj) &&
        arr[Newi][Newj] == arr[i][j] && DFS(Newi, Newj, i, j))
      return 1;
  }
  return 0;
}
int main() {
  cin >> RO >> CO;
  for (int i = 0; i < RO; i++) cin >> arr[i];
  for (int i = 0; i < RO; i++)
    for (int j = 0; j < CO; j++) {
      memset(vis, 0, sizeof vis);
      if (DFS(i, j, i, j)) {
        cout << "Yes";
        return 0;
      }
    }
  cout << "No";
  return 0;
}
