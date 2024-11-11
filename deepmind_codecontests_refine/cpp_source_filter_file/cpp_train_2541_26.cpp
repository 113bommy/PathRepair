#include <bits/stdc++.h>
using namespace std;
int N, D;
bool poss[500050];
int main() {
  for (int i = 0; i < 500050; i++) poss[i] = false;
  cin >> N >> D;
  poss[0] = true;
  for (int k = 0; k < N; k++) {
    int c;
    cin >> c;
    for (int i = 500049; i >= 0; i--) poss[i] |= poss[i - c];
  }
  int p = 0, d = 0;
  while (1) {
    int latest = -1;
    for (int i = p + 1; i <= p + D; i++) {
      if (poss[i]) latest = i;
    }
    if (latest == -1) break;
    p = latest;
    d++;
  }
  cout << p << ' ' << d;
  return 0;
}
