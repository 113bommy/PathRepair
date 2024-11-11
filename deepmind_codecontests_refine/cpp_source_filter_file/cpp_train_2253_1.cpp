#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int node[N][N], in[N][N];
vector<int> a;
vector<pair<int, int>> g[N][N];
short ans[N][N], lol, col[200 * N + 1], ten[5];
void fill(int at, int num, int freq) {
  if (!at && !freq) {
    a.push_back(num);
    col[num] = lol++;
    return;
  }
  if (!at) return;
  for (int i = 0; i <= freq; i++) fill(at - 1, num * 10 + i, freq - i);
}
void read(int &ref) {
  for (int i = 0, a; i < 8; i++) {
    scanf("%d", &a);
    ref += ten[a];
  }
}
int get(int a, int b) { return a / ten[b] % 10; }
int main() {
  fill(5, 0, 8);
  ten[0] = 1;
  for (int i = 1; i < 5; i++) ten[i] = ten[i - 1] * 10;
  queue<pair<int, int>> q;
  for (auto i : a)
    for (auto j : a)
      if (i == j && j == 8)
        continue;
      else if (i == 8 || j == 8) {
        ans[col[i]][col[j]] = (i != 8) + 1;
        q.push({col[i], col[j]});
      } else {
        for (int k = 1; k < 5; k++)
          for (int l = 1; l < 5; l++) {
            if (!get(i, k) || !get(j, l)) continue;
            int x = i - ten[k] + ten[(k + l) % 5];
            g[col[j]][col[x]].push_back({col[i], col[j]});
            in[col[i]][col[j]]++;
          }
      }
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (auto k : g[x][y]) {
      int i = k.first, j = k.second;
      if (ans[i][j]) continue;
      if (ans[x][y] == 2) {
        ans[i][j] = 1;
        q.push({i, j});
        continue;
      }
      if (!--in[i][j]) {
        ans[i][j] = 2;
        q.push({i, j});
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    bool win;
    scanf("%d", &win);
    int x = 0, y = 0;
    read(x);
    read(y);
    if (win) swap(x, y);
    x = col[x];
    y = col[y];
    if (ans[x][y] == 2)
      puts(!win ? "Bob" : "Alice");
    else if (ans[x][y] == 1)
      puts(win ? "Bob" : "Alice");
    else
      puts("Deal");
  }
}
