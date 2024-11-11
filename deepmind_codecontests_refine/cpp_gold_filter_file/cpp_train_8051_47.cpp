#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  float sum = 0;
  for (int i = 0; i < N; i++) {
    double val;
    cin >> val;
    sum += val / 100;
  }
  cout << sum / N * 100 << '\n';
  return 0;
}
