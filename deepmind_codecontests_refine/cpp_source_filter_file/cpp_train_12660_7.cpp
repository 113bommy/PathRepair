#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;
const int D = 4, di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
const int N = 250;
int n, m;
string quarters[N];
ll noise[N][N];
int used[N][N];
bool valid(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m && quarters[i][j] != '*';
}
void propagate(int i, int j, int initial_noise) {
  int ts = i * n + j;
  queue<tuple<int, int, int>> q;
  q.emplace(i, j, initial_noise);
  while (!q.empty()) {
    auto [i, j, cur_noise] = q.front();
    q.pop();
    if (used[i][j] == ts || cur_noise == 0) continue;
    used[i][j] = ts;
    noise[i][j] += cur_noise;
    for (int d = int(0); d < int(D); d++) {
      int ni = i + di[d], nj = j + dj[d];
      if (valid(ni, nj)) {
        q.emplace(ni, nj, cur_noise / 2);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q, p;
  cin >> n >> m >> q >> p;
  for (int i = int(0); i < int(n); i++) cin >> quarters[i];
  for (int i = int(0); i < int(n); i++)
    for (int j = int(0); j < int(m); j++)
      if (quarters[i][j] >= 'A' && quarters[i][j] <= 'Z') {
        int times = 1 + (quarters[i][j] - 'A');
        propagate(i, j, times * q);
      }
  int exc = 0;
  for (int i = int(0); i < int(n); i++)
    for (int j = int(0); j < int(m); j++)
      if (noise[i][j] > p) exc++;
  cout << exc << '\n';
  return 0;
}
