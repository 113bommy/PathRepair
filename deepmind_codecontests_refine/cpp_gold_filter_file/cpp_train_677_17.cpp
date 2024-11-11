#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > G;
const int N = 3010;
int n, m, ans[4], answer = 0;
int A1[N][2][2], A2[N][3][3];
int cost[N][N];
int visited_cities[N];
void bfs(int pos) {
  queue<pair<int, int> > myQueue;
  myQueue.push(make_pair(pos, 0));
  visited_cities[pos] = pos;
  bool b = true;
  while (!myQueue.empty()) {
    pair<int, int> cur_node = myQueue.front();
    if (b) {
      A1[pos][0][0] = cur_node.first;
      A1[pos][0][1] = cur_node.second;
    } else {
      A1[pos][1][0] = cur_node.first;
      A1[pos][1][1] = cur_node.second;
    }
    b = !b;
    myQueue.pop();
    for (int j = 0; j < G[cur_node.first].size(); j++) {
      if (visited_cities[G[cur_node.first][j]] != pos) {
        visited_cities[G[cur_node.first][j]] = pos;
        cost[pos][G[cur_node.first][j]] = cur_node.second + 1;
        myQueue.push(make_pair(G[cur_node.first][j], cur_node.second + 1));
      }
    }
  }
}
void calculate_A2(int pos) {
  for (int i = 1; i <= n; i++) {
    if (cost[pos][i] == 0) {
      continue;
    }
    for (int j = 0; j < 2; j++) {
      if (cost[pos][i] + A1[i][j][1] > A2[pos][2][2] and A1[i][j][0] != pos) {
        if (i == A1[i][j][0] or A1[i][j][0] == 0) {
          continue;
        }
        if (((i == A2[pos][0][0] or i == A2[pos][0][1]) and
             (i == A2[pos][1][0] or i == A2[pos][1][1])) or
            ((A1[i][j][0] == A2[pos][0][0] or A1[i][j][0] == A2[pos][0][1]) and
             (A1[i][j][0] == A2[pos][1][0] or A1[i][j][0] == A2[pos][1][1]))) {
          int temp_int = 1;
          if (cost[pos][i] + A1[i][j][1] > A2[pos][0][2]) {
            temp_int--;
          }
          if (temp_int != 1) {
            A2[pos][temp_int + 1][0] = A2[pos][temp_int][0];
            A2[pos][temp_int + 1][1] = A2[pos][temp_int][1];
            A2[pos][temp_int + 1][2] = A2[pos][temp_int][2];
          }
          A2[pos][temp_int][0] = i;
          A2[pos][temp_int][1] = A1[i][j][0];
          A2[pos][temp_int][2] = cost[pos][i] + A1[i][j][1];
        }
        int temp_int = 2;
        if (cost[pos][i] + A1[i][j][1] > A2[pos][1][2]) {
          temp_int--;
        }
        if (cost[pos][i] + A1[i][j][1] > A2[pos][0][2]) {
          temp_int--;
        }
        if (temp_int != 2) {
          A2[pos][temp_int + 1][0] = A2[pos][temp_int][0];
          A2[pos][temp_int + 1][1] = A2[pos][temp_int][1];
          A2[pos][temp_int + 1][2] = A2[pos][temp_int][2];
        }
        A2[pos][temp_int][0] = i;
        A2[pos][temp_int][1] = A1[i][j][0];
        A2[pos][temp_int][2] = cost[pos][i] + A1[i][j][1];
      }
    }
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (cost[i][j] != 0 and A2[j][0][2] + cost[i][j] > answer) {
        if (i != A2[j][0][0] and i != A2[j][0][1] and i != j) {
          answer = A2[j][0][2] + cost[i][j];
          ans[0] = i;
          ans[1] = j;
          ans[2] = A2[j][0][0];
          ans[3] = A2[j][0][1];
          continue;
        }
        if (i != A2[j][1][0] and i != A2[j][1][1] and i != j and
            A2[j][1][2] + cost[i][j] > answer) {
          answer = A2[j][1][2] + cost[i][j];
          ans[0] = i;
          ans[1] = j;
          ans[2] = A2[j][1][0];
          ans[3] = A2[j][1][1];
          continue;
        }
        if (i != A2[j][2][0] and i != A2[j][2][1] and i != j and
            A2[j][2][2] + cost[i][j] > answer) {
          answer = A2[j][1][2] + cost[i][j];
          ans[0] = i;
          ans[1] = j;
          ans[2] = A2[j][2][0];
          ans[3] = A2[j][2][1];
          continue;
        }
      }
    }
  }
}
int main() {
  int in1, in2;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> in1 >> in2;
    G[in1].push_back(in2);
  }
  for (int i = 1; i <= n; i++) {
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    calculate_A2(i);
  }
  solve();
  cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3];
  return 0;
}
