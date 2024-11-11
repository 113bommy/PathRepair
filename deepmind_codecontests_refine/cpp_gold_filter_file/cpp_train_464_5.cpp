#include <bits/stdc++.h>
using namespace std;
int N, K, M, X, Y, Sol, T[100005];
int main() {
  cin >> N >> K;
  Sol = N - 1;
  while (K--) {
    Y = 0;
    cin >> M;
    Sol += M - 1;
    for (int j = 1; j <= M; j++) cin >> T[j];
    if (T[1] == 1) {
      Y = 2;
      while (T[Y] == Y) Y++;
      Y -= 2;
    }
    if (Y > 0) Sol -= 2 * Y;
  }
  cout << Sol;
  return 0;
}
