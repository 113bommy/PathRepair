#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string S;
  cin >> N >> S;
  int w = 0, b = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '.') w++;
  }
  int res = 1 << 28;
  for (int i = 0; i < N; i++) {
    if (S[i] == '.') w--;
    if (S[i] == '#') b++;
    res = min(res, w + b);
  }
  cout << res << '\n';
  return 0;
}
