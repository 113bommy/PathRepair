#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N, len = 0;
  cin >> N;
  string S;
  cin >> S;
  for (int i = 0; i < N - 10; i++) {
    if (S[i] == '8') len++;
  }
  len *= 2;
  if (N - len >= 11)
    cout << "NO\n";
  else
    cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}
