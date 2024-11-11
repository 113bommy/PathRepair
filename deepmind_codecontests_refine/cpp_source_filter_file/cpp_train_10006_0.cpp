#include <bits/stdc++.h>
using namespace std;
int N;
void add(int x, int y, vector<vector<int>>& cnt, vector<pair<int, int>>& pos) {
  if (x < 0 || x >= N || y < 0 || y >= N) return;
  cnt[x][y]++;
  if (cnt[x][y] >= 4) {
    cnt[x][y] = -100;
    pos.push_back({x, y});
  }
}
bool simulate(vector<pair<int, int>> pos) {
  vector<vector<int>> cnt(N, vector<int>(N));
  for (auto i : pos) {
    cnt[i.first][i.second] = -100;
  }
  int counter = 0;
  while (pos.size()) {
    pair<int, int> x = pos[0];
    swap(pos[0], pos.back());
    pos.pop_back();
    counter++;
    add(x.first + 1, x.second + 2, cnt, pos);
    add(x.first + 1, x.second - 2, cnt, pos);
    add(x.first - 1, x.second + 2, cnt, pos);
    add(x.first - 1, x.second - 2, cnt, pos);
    add(x.first + 2, x.second + 1, cnt, pos);
    add(x.first + 2, x.second - 1, cnt, pos);
    add(x.first - 2, x.second + 1, cnt, pos);
    add(x.first - 2, x.second - 1, cnt, pos);
  }
  cerr << "counter: " << counter << '\n';
  return counter == N * N;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n <= 40) {
    N = n;
    for (int i = 1; i <= n / 2; ++i) {
      cout << i << ' ' << i + 1 << '\n';
      cout << i << ' ' << i - 1 << '\n';
    }
    if (n % 2 == 1) {
      cout << n / 2 + 1 << ' ' << n / 2 + 2 << '\n';
    }
    return 0;
  }
  vector<vector<bool>> tab(n + 2, vector<bool>(n + 2));
  int side = (n - 0) * 3 / 10 + 2;
  N = 3 * side;
  cerr << "side: " << side << '\n';
  for (int i = 1; i <= side; ++i) {
    tab[i][side - i + 2] = tab[i][side - i] = 1;
    if (i <= side / 3 || side - i + 1 <= side / 3) {
      tab[i][i + 1] = 1;
      tab[i][i - 1] = 1;
    }
  }
  int cnt = 0;
  vector<pair<int, int>> pos;
  for (int i = 1; i <= side; ++i) {
    for (int j = 1; j <= side; ++j) {
      if (tab[i][j]) {
        pos.push_back({side + i - 1, side + j - 1});
        cout << i << ' ' << j << '\n';
        cnt++;
      }
    }
  }
  for (int i = 2; i <= n - cnt + 1; ++i) {
    cout << 1 << ' ' << side + i << '\n';
    pos.push_back({side + side + i / 2, side + i % 2 + 1});
  }
  cerr << cnt - n << '\n';
  if (cnt > n) cerr << "fail. To many points\n";
  if (!simulate(pos)) cerr << "fail. Square is not filled\n";
}
