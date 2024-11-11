#include <bits/stdc++.h>
using namespace std;
long long int N, M, Max = 0, Maxj = 0, A[1000][1000], arr[1000][1] = {};
int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    Max = 0;
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      if (Max < A[i][j]) {
        Max = A[i][j];
        Maxj = j;
      }
    }
    arr[Maxj][0]++;
  }
  long long int Max = 0, ind;
  for (int i = 0; i < N; i++) {
    if (Max < arr[i][0]) {
      Max = arr[i][0];
      ind = i + 1;
    }
  }
  cout << ind;
  return 0;
}
