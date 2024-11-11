#include <bits/stdc++.h>
using namespace std;
int n, m;
tuple<int, int, int> queens[100000];
int w[100000];
int freq[9];
void rotate90();
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    queens[i] = make_tuple(x, y, i);
  }
  for (int k = 0; k < 4; k++) {
    solve();
    rotate90();
  }
  for (int i = 0; i < m; i++) freq[w[i]]++;
  for (int j = 0; j <= 8; j++) cout << freq[j] << ' ';
  cout << '\n';
  return 0;
}
int pres[2 * 100000];
void solve() {
  sort(queens, queens + m);
  int x, y, i;
  memset(pres, 0, sizeof(pres));
  for (int j = 0; j < m; j++) {
    tie(x, y, i) = queens[j];
    if (pres[x]) w[i]++;
    pres[x] = 1;
  }
  memset(pres, 0, sizeof(pres));
  for (int j = 0; j < m; j++) {
    tie(x, y, i) = queens[j];
    if (pres[x - y + n - 1]) w[i]++;
    pres[x - y + n - 1] = 1;
  }
}
void rotate90() {
  int x, y, i;
  for (int j = 0; j < m; j++) {
    tie(x, y, i) = queens[j];
    queens[j] = make_tuple(y, n - x - 1, i);
  }
}
