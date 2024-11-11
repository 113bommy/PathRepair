#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  pair<int, int> P;
  vector<pair<int, int>> V;
  char arr[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == '*') V.push_back({i, j});
    }
  }
  if (V[0].first - V[1].first == 0 && V[2].second != V[1].second) {
    P.first = V[2].first + 1;
    P.second = V[1].second + 1;
  } else if (V[0].first - V[1].first == 0 && V[2].second == V[1].second) {
    P.first = V[2].first + 1;
    P.second = V[0].second + 1;
  } else if (V[1].first - V[2].first == 0 && V[0].second == V[1].second) {
    P.first = V[0].first + 1;
    P.second = V[2].second + 1;
  } else if (V[1].first - V[2].first == 0 && V[0].second != V[1].second) {
    P.first = V[0].first + 1;
    P.second = V[2].second + 1;
  }
  cout << P.first << " " << P.second;
  return 0;
}
