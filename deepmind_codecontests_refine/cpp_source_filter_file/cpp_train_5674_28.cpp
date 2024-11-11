#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, arr[100][100];
  cin >> n >> m;
  long long i, j;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  long long maxx = 0, jph = 0;
  for (i = 0; i < m; i++) {
    maxx = 0;
    for (j = 0; j < n; j++) {
      if (arr[i][j] > maxx) {
        maxx = arr[i][j];
        jph = j;
      }
    }
    arr[i][jph] = -1;
  }
  long long new_arr[100] = {0}, cnt = 0;
  for (j = 0; j < n; j++) {
    cnt = 0;
    for (i = 0; i < m; i++) {
      if (arr[i][j] == -1) {
        cnt++;
      }
    }
    new_arr[j] = cnt;
  }
  maxx = 0;
  long long iph = 0;
  for (i = 0; i < n; i++) {
    if (new_arr[i] > maxx) {
      maxx = new_arr[i];
      iph = i;
    }
  }
  cout << iph + 1;
  return 0;
}
