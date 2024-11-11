#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int table[1000][1000];
  for (int k = 2; k < 1000; k++) {
    if (k * (k + 1) == N * 2) {
      cout << "Yes" << endl;
      cout << k + 1 << endl;
      int count = 1;
      for (int i = 0; i < k; i++) {
        for (int j = i; j < k; j++) {
          table[i][j] = count;
          table[j + 1][i] = count;
          count++;
        }
      }
      for (int i = 0; i < k + 1; i++) {
        cout << k << ' ';
        for (int j = 0; j < k; j++) {
          cout << table[i][j];
          if (j < k - 1) cout << ' ';
        }
        cout << endl;
      }
      return 0;
    }
  }
  cout << "No" << endl;
}
