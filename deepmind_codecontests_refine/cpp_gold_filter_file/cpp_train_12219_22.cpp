#include <bits/stdc++.h>
using namespace std;
int N, K, a;
int W[5] = {0};
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> K;
    W[i % 3] += K;
  }
  int temp = 0;
  for (int i = 0; i < 3; i++) {
    if (W[i] > temp) {
      temp = W[i];
      a = i;
    }
  }
  if (a == 0)
    cout << "chest";
  else if (a == 1)
    cout << "biceps";
  else
    cout << "back";
  return 0;
}
