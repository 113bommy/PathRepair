#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
}
int main() {
  FastIO();
  int N;
  int A[200][200];
  cin >> N;
  int Count = 0;
  int Cars[1000] = {0};
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      if (A[i][j] == 0) {
        if (Cars[i + 1] == 0) Cars[i + 1] = 100;
        if (Cars[j + 1] == 0) Cars[j + 1] = 100;
      } else if (A[i][j] == 1) {
        Cars[i + 1] = -100;
      } else if (A[i][j] == 2)
        Cars[j + 1] = -100;
      else if (A[i][j] == 3) {
        Cars[i + 1] = -100;
        Cars[j + 1] = -100;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    if (Cars[i] != -100) {
      Count++;
    }
  }
  cout << Count << endl;
  for (int i = 1; i <= N; i++) {
    if (Cars[i] != -100) cout << i << " ";
  }
  return 0;
}
