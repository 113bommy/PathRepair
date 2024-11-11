#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  int A[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> A[i];
  }
  set<int> All;
  map<int, int> map1;
  map<int, int> map2;
  for (i = 1; i <= n; i++) {
    if (A[i] <= 100000) {
      map1[A[i]]++;
    }
  }
  for (i = 1; i <= 100000; i++) {
    if (map1[i] >= i) {
      All.insert(i);
    }
  }
  int t = All.size();
  int B[t + 1];
  i = 0;
  for (set<int>::iterator it = All.begin(); it != All.end(); it++) {
    i++;
    B[i] = *it;
    map2[*it] = i;
  }
  int Grid[n + 1][t + 1];
  for (i = 0; i <= 0; i++) {
    for (j = 1; j <= t; j++) {
      Grid[i][j] = 0;
    }
  }
  for (i = 1; i <= 1; i++) {
    for (j = 1; j <= t; j++) {
      Grid[i][j] = 0;
    }
    Grid[i][map2[A[i]]]++;
  }
  for (i = 2; i <= n; i++) {
    for (j = 1; j <= t; j++) {
      Grid[i][j] = Grid[i - 1][j];
    }
    Grid[i][map2[A[i]]]++;
  }
  for (i = 1; i <= m; i++) {
    int r, l;
    int cou = 0;
    cin >> r >> l;
    for (j = 1; j <= t; j++) {
      if (Grid[l][j] - Grid[r - 1][j] == B[j]) {
        cou++;
      }
    }
    cout << cou << "\n";
  }
  return 0;
}
