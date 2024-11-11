#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
string g[111];
void add(int x, int y) {
  g[x][y] = '1';
  g[y][x] = '1';
}
vector<int> v;
int main() {
  int e, i;
  cin >> e;
  int k;
  for (k = 100; k; k--) {
    int x = k * (k - 1) * (k - 2) / 6;
    if (x <= e) {
      e -= x;
      break;
    }
  }
  while (e > 0) {
    for (i = k; i; i--) {
      int x = i * (i - 1) / 2;
      if (x <= e) {
        e -= x;
        break;
      }
    }
    v.push_back(i);
  }
  int n = k + v.size();
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) g[i] += '0';
  for (int i = 0; i < (k); ++i)
    for (int j = 0; j < (i); ++j) add(i, j);
  for (int i = 0; i < (v.size()); ++i)
    for (int j = 0; j < (v[i]); ++j) add(k + i, j);
  cout << n << "\n";
  for (int i = 0; i < (n); ++i) cout << g[i] << "\n";
  return 0;
}
