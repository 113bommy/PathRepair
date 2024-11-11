#include <bits/stdc++.h>
using namespace std;
int graph[1005][1005]{0};
int main() {
  int n;
  cin >> n;
  int b;
  if (n == 4) {
    cout << "-1" << endl;
    return 0;
  }
  if (n & 1) {
    b = n;
  } else {
    b = n - 1;
  }
  for (int i = 0; i < b; i++) {
    for (int j = 1; j + j < b; j++) {
      graph[i][(i + j) % b] = 1;
    }
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n - 1; i++) {
      if (i % 2 == 0) {
        graph[i][n - 1] = 1;
      } else {
        graph[n - 1][i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}
