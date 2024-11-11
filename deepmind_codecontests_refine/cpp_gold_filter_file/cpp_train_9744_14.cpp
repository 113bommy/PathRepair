#include <bits/stdc++.h>
using namespace std;
int main() {
  double X, Y, sum = 0;
  int N;
  cin >> N >> X;
  for (int i = 0; i < N; i++) {
    cin >> Y;
    sum += Y;
  }
  double p, ans = (double)sum / N;
  for (int i = 0; i <= 100000; i++) {
    p = sum / (N + i);
    if (p >= (X - 0.5)) {
      cout << i << endl;
      break;
    }
    sum += X;
  }
}
