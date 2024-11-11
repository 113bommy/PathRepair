#include <bits/stdc++.h>
using namespace std;
int N, P, L, R, F, i, j;
string S, T[4] = {">", ">=", "<", "<="};
map<string, int> M;
char C;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  R = 1e9 + 1;
  L = -R;
  for (i = 0; i < 4; i++) {
    M[T[i]] = i;
  }
  cin >> N;
  for (i = 0; i < N; i++) {
    cin >> S >> P >> C;
    F = M[S];
    if (C == 'N') {
      F = 3 - F;
    }
    if (F < 2) {
      L = max(L, P + 1 - F);
    } else {
      R = min(R, P - 3 + F);
    }
  }
  if (L > N) {
    cout << "Impossible\n";
  } else {
    cout << (L + R) / 2 << '\n';
  }
}
