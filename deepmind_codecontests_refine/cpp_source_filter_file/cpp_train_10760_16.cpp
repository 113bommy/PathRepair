#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n, s;
  cin >> n >> s;
  long long int list[s][n];
  for (long long int i = 0; i < n; i++) {
    long long int temp;
    cin >> temp;
    list[i][0] = temp;
  }
  for (long long int i = 1, k = 0, l = 1; i <= n * s; i++) {
    bool check = 0;
    for (long long int j = 0; j < n; j++) {
      if (i == list[j][0]) {
        check = 1;
        break;
      }
    }
    if (!check) {
      list[k][l] = i;
      l++;
    }
    if (l >= n) {
      k++;
      l = 1;
    }
  }
  for (long long int i = 0; i < s; i++) {
    for (long long int j = 0; j < n; j++) cout << list[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
