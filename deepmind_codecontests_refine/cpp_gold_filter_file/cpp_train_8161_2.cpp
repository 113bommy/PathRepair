#include <bits/stdc++.h>
using namespace std;
long long int dx[] = {-1, +1, 0, 0, +1, -1, +1, -1};
long long int dy[] = {0, 0, -1, +1, +1, +1, -1, -1};
const long long int mx = 1e5 + 123;
bool vis[mx];
vector<long long int> adj[mx];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long int a, i, j, k, c;
  cin >> a >> c;
  long long int b[a * a];
  memset(b, -1, sizeof(b));
  k = 1;
  for (i = 0; i < a; i++) {
    for (j = 0; j < a; j++) {
      if (j == i) {
        cout << c << " ";
      } else
        cout << "0 ";
    }
    cout << endl;
  }
}
