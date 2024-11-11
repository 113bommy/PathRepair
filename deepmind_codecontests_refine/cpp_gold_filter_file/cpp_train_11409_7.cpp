#include <bits/stdc++.h>
using namespace std;
int A[100010];
int B[100010];
int N;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N - 1; i++) {
    B[i] = abs(A[i] - A[i + 1]);
  }
  long long ThisSum, MaxSum, j;
  ThisSum = MaxSum = 0;
  for (j = 0; j < N - 1; j++) {
    ThisSum += B[j] * (j % 2 == 1 ? -1 : 1);
    if (ThisSum > MaxSum)
      MaxSum = ThisSum;
    else if (ThisSum < 0) {
      ThisSum = 0;
    }
  }
  ThisSum = 0;
  for (j = 1; j < N - 1; j++) {
    ThisSum += B[j] * (j % 2 == 0 ? -1 : 1);
    if (ThisSum > MaxSum)
      MaxSum = ThisSum;
    else if (ThisSum < 0) {
      ThisSum = 0;
    }
  }
  cout << MaxSum << endl;
  return 0;
}
