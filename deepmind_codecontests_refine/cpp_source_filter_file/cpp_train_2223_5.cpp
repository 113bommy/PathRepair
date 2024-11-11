#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int x[100005];
int y[100005];
bool visited[105][105];
int n;
void dfs(int x_cod, int y_cod) {
  int i;
  visited[x_cod][y_cod] = true;
  for (i = 1; i <= n; i++) {
    if (x[i] == x_cod || y[i] == y_cod) {
      if (!visited[x[i]][y[i]]) {
        dfs(x[i], y[i]);
      }
    }
  }
}
int main() {
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> x[i];
    cin >> y[i];
  }
  long long int cont = 0;
  for (i = 1; i <= n; i++) {
    if (!visited[x[i]][y[i]]) {
      cont++;
      dfs(x[i], y[i]);
    }
  }
  cout << cont - 1 << endl;
  return 0;
}
