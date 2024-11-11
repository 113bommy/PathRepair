#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX = 200005;
const double PI = 3.14159265358979323846;
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
void printvi(vector<int> arr) {
  for (int i = 0; i < (int)(((int)((arr).size()))); i++) cout << arr[i] << " ";
  cout << "\n";
}
void printvll(vector<long long> arr) {
  for (int i = 0; i < (int)(((int)((arr).size()))); i++) cout << arr[i] << " ";
  cout << "\n";
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int arr[n][m], r[n], c[m];
  for (int i = 0; i < n; i++) r[i] = i;
  for (int i = 0; i < m; i++) c[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    char kind;
    cin >> kind >> x >> y;
    x--;
    y--;
    if (kind == 'r') {
      int temp = r[x];
      r[x] = r[y];
      y = temp;
    } else if (kind == 'c') {
      int temp = c[x];
      c[x] = c[y];
      c[y] = temp;
    } else {
      cout << arr[r[x]][c[y]] << "\n";
    }
  }
}
int main() {
  run();
  solve();
  return 0;
}
