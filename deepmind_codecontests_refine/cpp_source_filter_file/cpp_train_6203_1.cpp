#include <bits/stdc++.h>
using namespace std;
long long int n = 0;
long long int m = 0;
bool equals(pair<long long int, long long int>& a,
            pair<long long int, long long int>& b) {
  return (a.first == b.first && a.second == b.second);
}
bool checkPath(string direction, pair<long long int, long long int>& cell,
               vector<vector<bool>>& grid) {
  if (direction == "U") {
    return (((cell.first - 1) >= 0) && (grid[cell.first - 1][cell.second]));
  }
  if (direction == "D") {
    return (((cell.first + 1) < n) && (grid[cell.first + 1][cell.second]));
  }
  if (direction == "L") {
    return (((cell.second - 1) >= 0) && (grid[cell.first][cell.second - 1]));
  }
  if (direction == "R") {
    return (((cell.second + 1) < m) && (grid[cell.first][cell.second + 1]));
  }
}
string solve(pair<long long int, long long int> start,
             vector<vector<bool>>& grid, long long int k,
             vector<vector<long long int>>& dist) {
  if (k % 2 == 1) {
    return "IMPOSSIBLE";
  }
  if ((!checkPath("U", start, grid)) && (!checkPath("D", start, grid)) &&
      (!checkPath("R", start, grid)) && (!checkPath("L", start, grid))) {
    return "IMPOSSIBLE";
  }
  long long int stepsRemaining = k;
  pair<long long int, long long int> curr = start;
  string answer = "";
  while (stepsRemaining > 0) {
    stepsRemaining--;
    if (checkPath("D", curr, grid)) {
      if (stepsRemaining >= dist[curr.first + 1][curr.second]) {
        answer += "D";
        curr = make_pair(curr.first + 1, curr.second);
        continue;
      }
    }
    if (checkPath("L", curr, grid)) {
      if (stepsRemaining >= dist[curr.first][curr.second - 1]) {
        answer += "L";
        curr = make_pair(curr.first, curr.second - 1);
        continue;
      }
    }
    if (checkPath("R", curr, grid)) {
      if (stepsRemaining >= dist[curr.first][curr.second + 1]) {
        answer += "R";
        curr = make_pair(curr.first, curr.second + 1);
        continue;
      }
    }
    if (checkPath("U", curr, grid)) {
      if (stepsRemaining >= dist[curr.first - 1][curr.second]) {
        answer += "U";
        curr = make_pair(curr.first - 1, curr.second);
        continue;
      }
    }
  }
  return answer;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int k;
  cin >> n >> m >> k;
  vector<vector<bool>> grid(n, vector<bool>(m, false));
  pair<long long int, long long int> dest = make_pair(-1, -1);
  for (long long int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (long long int j = 0; j < m; j++) {
      if (row[j] == '.') {
        grid[i][j] = true;
      } else if (row[j] == 'X') {
        grid[i][j] = true;
        dest = make_pair(i, j);
      }
    }
  }
  vector<vector<long long int>> dist(n, vector<long long int>(m, 2 * k));
  vector<vector<bool>> visited(n, vector<bool>(m, false));
  queue<pair<long long int, long long int>> Queue;
  Queue.push(dest);
  dist[dest.first][dest.second] = 0;
  visited[dest.first][dest.second] = 0;
  while (!Queue.empty()) {
    pair<long long int, long long int> temp = Queue.front();
    Queue.pop();
    if (checkPath("U", temp, grid)) {
      if (!visited[temp.first - 1][temp.second]) {
        visited[temp.first - 1][temp.second] = true;
        dist[temp.first - 1][temp.second] = dist[temp.first][temp.second] + 1;
        Queue.push(make_pair(temp.first - 1, temp.second));
      }
    }
    if (checkPath("D", temp, grid)) {
      if (!visited[temp.first + 1][temp.second]) {
        visited[temp.first + 1][temp.second] = true;
        dist[temp.first + 1][temp.second] = dist[temp.first][temp.second] + 1;
        Queue.push(make_pair(temp.first + 1, temp.second));
      }
    }
    if (checkPath("L", temp, grid)) {
      if (!visited[temp.first][temp.second - 1]) {
        visited[temp.first][temp.second - 1] = true;
        dist[temp.first][temp.second - 1] = dist[temp.first][temp.second] + 1;
        Queue.push(make_pair(temp.first, temp.second - 1));
      }
    }
    if (checkPath("R", temp, grid)) {
      if (!visited[temp.first][temp.second + 1]) {
        visited[temp.first][temp.second + 1] = true;
        dist[temp.first][temp.second + 1] = dist[temp.first][temp.second] + 1;
        Queue.push(make_pair(temp.first, temp.second + 1));
      }
    }
  }
  cout << solve(dest, grid, k, dist);
  return 0;
}
