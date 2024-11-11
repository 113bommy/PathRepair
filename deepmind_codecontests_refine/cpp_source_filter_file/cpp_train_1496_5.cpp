#include <bits/stdc++.h>
using namespace std;
inline long long pos_mod(long long i, long long n) { return (i % n + n) % n; }
int length(int root, vector<bool>& visited, vector<vector<int> >& adj_mat,
           vector<int>& colored, bool to_color) {
  visited[root] = true;
  int days = 0;
  for (int i = 0; i < 100; i++) {
    if (adj_mat[root][i] == -1) continue;
    adj_mat[root][i] ^= to_color;
    adj_mat[i][root] ^= to_color;
    if (visited[i] && adj_mat[root][i] == 0) {
      return 250;
    }
  }
  for (int i = 0; i < 100; i++) {
    if (adj_mat[root][i] == -1 || visited[i]) continue;
    int novi = length(i, visited, adj_mat, colored, 1 - adj_mat[root][i]);
    days += novi;
  }
  if (to_color) colored.push_back(root);
  return days + to_color;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<vector<int> > adjmat1(100, vector<int>(100, -1));
  vector<vector<int> > adjmat2(100, vector<int>(100, -1));
  vector<bool> visited1(100);
  vector<bool> visited2(100);
  vector<bool> colored;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < (m); i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    adjmat1[a][b] = c;
    adjmat1[b][a] = c;
    adjmat2[a][b] = c;
    adjmat2[b][a] = c;
  }
  vector<int> c;
  for (int i = 0; i < n; i++) {
    if (!visited1[i]) {
      vector<int> c1;
      vector<int> c2;
      int res1 = length(i, visited1, adjmat1, c1, false);
      int res2 = length(i, visited2, adjmat2, c2, true);
      if (res1 >= 250 && res2 >= 250) {
        cout << "Impossible" << endl;
        return 0;
      }
      if (res1 < res2) {
        for (int a : c1) c.push_back(a);
      } else {
        for (int a : c2) c.push_back(a);
      }
    }
  }
  if (c.size() > n) {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << c.size() << endl;
  for (int i = 0; i < c.size(); i++) {
    cout << c[i] << " ";
  }
}
