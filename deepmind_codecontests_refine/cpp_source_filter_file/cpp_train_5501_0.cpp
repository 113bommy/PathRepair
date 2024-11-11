#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, K;
  cin >> N >> M >> K;
  string ans = "No";
  for (int n = 0; n <= N; n++)
    for (int m = 0; m <= M; m++)
      if (n * (N - m) + m * (M - n) == K) ans = "Yes";
  cout << ans << endl;
}
