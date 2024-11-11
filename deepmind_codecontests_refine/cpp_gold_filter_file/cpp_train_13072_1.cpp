#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int N = 300009;
const int LOG = 20;
int cycles;
void d(int curr, vector<int> &v, vector<vector<int>> &g) {
  v[curr] = 1;
  for (auto c : g[curr]) {
    if (v[c] == 0) {
      d(c, v, g);
    } else if (v[c] == 1) {
      cycles++;
    }
  }
  v[curr] = -1;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<vector<int>> grev(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    g[i].push_back(x - 1);
    grev[x - 1].push_back(i);
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    count += b[i];
  }
  vector<int> v(n, 0);
  vector<int> order;
  cycles = 0;
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      d(i, v, g);
    }
  }
  if (count == 0) {
    cout << (cycles == 1 ? 1 : cycles + 1);
  } else if (count == 1) {
    cout << (cycles == 1 ? 0 : cycles);
  } else {
    if (count % 2 == 0) {
      cout << (cycles == 1 ? 1 : cycles + 1);
    } else
      cout << (cycles == 1 ? 0 : cycles);
  }
}
int main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
}
