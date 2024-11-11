#include <bits/stdc++.h>
using namespace std;
void MAIN() {
  long long N;
  cin >> N;
  string S = to_string(N);
  int sz = int(S.size());
  if (sz == 1) {
    cout << N - 1 << "\n";
    return;
  }
  string S1;
  string S2;
  for (int i = 0; i < sz; i++) {
    if (i % 2 == 0) {
      S1 += S[i];
    } else {
      S2 += S[i];
    }
  }
  cout << (stoi(S1) + 1) * (stoi(S2) + 1) - 2 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    MAIN();
  }
  return 0;
}
