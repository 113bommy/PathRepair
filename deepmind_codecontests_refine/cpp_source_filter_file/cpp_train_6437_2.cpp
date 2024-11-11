#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  int ans = 0;
  for (int i = 0; i + 1 < N; i++) {
    if (S.at(i) != S.at(i + 1)) ans = max(ans, max(i + 1, N - i - 1));
  }
  cout << ans << "\n";
}
