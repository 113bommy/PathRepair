#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int N = 2e5 + 10, M = 1e6 + 10, OOm = 0x3f3f3f3f;
string blank = "";
bool fin[20];
int arr[20];
int n, m, x;
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) cin >> x, fin[x] = 1;
  for (int i = 0; i < n; i++) {
    if (fin[arr[i]]) cout << arr[i] << ' ';
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
}
