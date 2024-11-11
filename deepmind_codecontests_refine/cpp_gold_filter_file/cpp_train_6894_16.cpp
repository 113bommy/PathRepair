#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, N, M;
  cin >> T;
  while (T--) {
    cin >> N >> M;
    if (N % M == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
