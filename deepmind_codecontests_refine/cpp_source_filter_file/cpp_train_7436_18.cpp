#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX_N = 111;
int main() {
  ios::sync_with_stdio(0);
  int N, K;
  char S[MAX_N];
  while (cin >> N >> K) {
    cin >> S;
    int d = 0;
    if (2 * K > N) {
      d = -1;
      while (K < N) {
        cout << "RIGHT" << '\n';
        K++;
      }
    } else {
      d = +1;
      while (K > N) {
        cout << "LEFT" << '\n';
        K--;
      }
    }
    bool space = false;
    while (1 <= K && K <= N) {
      if (space) {
        if (d == 1) cout << "RIGHT" << '\n';
        if (d == -1) cout << "LEFT" << '\n';
      }
      space = true;
      cout << "PRINT " << S[K - 1] << '\n';
      K += d;
    }
    cout << endl;
  }
  return 0;
}
