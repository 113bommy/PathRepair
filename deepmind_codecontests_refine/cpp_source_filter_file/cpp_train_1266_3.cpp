#include <bits/stdc++.h>
using namespace std;
int N, T, M, K;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  long long ans = 1, cur = 4;
  for (int i = 1; i < N; i++) {
    ans += cur;
    cur *= 2;
  }
  cout << ans << endl;
  return 0;
}
