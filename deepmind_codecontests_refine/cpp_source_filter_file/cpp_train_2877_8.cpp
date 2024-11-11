#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(100000 + 1);
int count1 = 0;
int col[100000 + 1];
void DFS(int nd, int par) {
  if (col[nd] != col[par]) count1++;
  for (int i = 0; i < v[nd].size(); i++) DFS(v[nd][i], nd);
}
int main() {
  int n, a;
  cin >> n;
  int k = 2;
  for (int i = 0; i < n - 1; i++) {
    cin >> a;
    v[a].push_back(k);
    k++;
  }
  for (int i = 0; i < n; i++) {
    cin >> col[i];
  }
  DFS(1, 0);
  cout << count1 + 1 << endl;
  return 0;
}
