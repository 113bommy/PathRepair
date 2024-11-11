#include <bits/stdc++.h>
using namespace std;
int V[200];
int main() {
  int N, A, B;
  cin >> N >> A >> B;
  if (B == 0 && A > 0 && A >= N - 1) {
    cout << -1 << endl;
    return 0;
  }
  int sum = 1;
  V[0] = 1;
  V[1] = 1;
  for (int i = 1; i <= B; i++) {
    V[i] = sum + 1;
    if (V[i] > 50000) {
      cout << -1 << endl;
      return 0;
    }
    sum += V[i];
  }
  int x = 1;
  if (B == 0) x = 2;
  for (int i = B + x; i <= (A + B + x - 1); i++) {
    V[i] = V[i - 1] + 1;
    sum += V[i];
  }
  for (int i = A + B + x; i < N; i++) {
    V[i] = 1;
  }
  bool space = false;
  for (int i = 0; i < N; i++) {
    if (space) cout << " ";
    space = true;
    cout << V[i];
  }
  cout << endl;
}
