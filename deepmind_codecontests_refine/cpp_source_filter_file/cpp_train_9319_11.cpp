#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  int ans = 0;
  int tmp_a, tmp_b;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      tmp_a = tmp_b = 0;
      for (int x = i; x <= j; x++) {
        tmp_a |= a[x];
        tmp_b |= b[x];
      }
      ans = max(tmp_a + tmp_b, ans);
    }
  }
  cout << ans;
}
