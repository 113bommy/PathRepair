#include <bits/stdc++.h>
using namespace std;
int main() {
  char array[100][100];
  int a[100][100], c[100];
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> array[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[j][i] = array[i][j] - 48;
    }
  }
  int count = 0;
  for (int i = 0; i < m; i++) {
    int max = *max_element(a[i], a[i] + n);
    for (int j = 0; j < n; j++) {
      if (a[i][j] == max) c[i] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (c[i] == 1) count++;
  cout << count << endl;
  cin >> n;
}
