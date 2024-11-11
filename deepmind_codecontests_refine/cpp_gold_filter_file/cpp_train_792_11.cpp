#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  char Arr[N][M];
  string S;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> Arr[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int count1 = 0;
      for (int k = 0; k < N; k++) {
        if (Arr[i][j] == Arr[k][j]) {
          count1++;
        }
      }
      for (int l = 0; l < M; l++) {
        if (Arr[i][j] == Arr[i][l]) {
          count1++;
        }
      }
      if (count1 == 2) {
        S += Arr[i][j];
      }
    }
  }
  cout << S << endl;
  return 0;
}
