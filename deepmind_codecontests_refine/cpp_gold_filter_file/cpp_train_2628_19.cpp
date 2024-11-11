#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    int N, M;
    cin >> N >> M;
    if (N == 1 || M == 1 || (N == 2 && M == 2))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
