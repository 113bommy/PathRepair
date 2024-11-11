#include <bits/stdc++.h>
using namespace std;
string mat[50];
int track[50];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  for (int i = 0; i < m; i++) {
    track[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '#') {
        if (track[j] == -1)
          track[j] = i;
        else if (mat[i] != mat[track[i]]) {
          return cout << "No", 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
