#include <bits/stdc++.h>
using namespace std;
int count_sort[11];
long long A[100004];
int main() {
  int N;
  long long temp;
  long long K, score = 0;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    score += A[i] / 10;
    if (A[i] % 10 == 0)
      count_sort[10] += (100 - A[i]) / 10;
    else {
      count_sort[10 - A[i] % 10]++;
      count_sort[10] += (100 - (A[i] + 10 - A[i] % 10)) / 10;
    }
  }
  for (int i = 1; i <= 10; i++) {
    if (K <= 0) break;
    temp = count_sort[i] * i;
    if (temp > K) {
      score += K / i;
      K = K - K / i;
    } else {
      score += count_sort[i];
      K = K - temp;
    }
  }
  cout << score << endl;
  return 0;
}
