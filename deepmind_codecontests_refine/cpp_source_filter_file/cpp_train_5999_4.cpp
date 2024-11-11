#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int K;
  cin >> K;
  int m = 0;
  for (int i = 0; i < K; ++i) {
    int r;
    cin >> r;
    if (r > m) {
      m = r;
    }
  }
  int diff = max(0, m - K);
  cout << diff << '\n';
  return 0;
}
