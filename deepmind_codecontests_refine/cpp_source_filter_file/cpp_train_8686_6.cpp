#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &arr, vector<vector<int>> &visited, int rowarr[],
         int colarr[], int srcx, int srcy) {
  visited[srcx][srcy] = 1;
  for (int i = 0; i < 4; i++) {
    int n = arr.size();
    int m = arr[0].size();
    int newx = srcx + rowarr[i];
    int newy = srcy + colarr[i];
    if ((newx >= 0) && (newx < n) && (newy >= 0) && (newx < m) &&
        (visited[newx][newy] == 0) && (arr[newx][newy] != '-')) {
      if (arr[srcx][srcy] == 'W') {
        arr[newx][newy] = 'B';
      } else {
        arr[newx][newy] = 'W';
      }
      dfs(arr, visited, rowarr, colarr, newx, newy);
    }
  }
  return;
}
int main() {
  int n = 0;
  int m = 0;
  cin >> n >> m;
  vector<vector<char>> arr;
  for (int i = 0; i < n; i++) {
    vector<char> v1;
    arr.push_back(v1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char element;
      cin >> element;
      arr[i].push_back(element);
    }
  }
  int rowarr[4] = {-1, 0, 1, 0};
  int colarr[4] = {0, 1, 0, -1};
  vector<vector<int>> visited;
  for (int i = 0; i < n; i++) {
    vector<int> v1;
    visited.push_back(v1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      visited[i].push_back(0);
    }
  }
  int srcx = 0;
  int srcy = 0;
  int got = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '.') {
        if (visited[i][j] == 0) {
          arr[i][j] = 'W';
          dfs(arr, visited, rowarr, colarr, i, j);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
