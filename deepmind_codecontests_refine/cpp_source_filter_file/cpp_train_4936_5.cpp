#include <bits/stdc++.h>
using namespace std;
int main() {
  const int MAX = 1e6;
  int n, k;
  cin >> n >> k;
  vector<int> cnt(MAX + 2);
  while (n--) {
    int a;
    cin >> a;
    cnt[a + 1]++;
  }
  for (int i = 0; i < MAX; i++) cnt[i + 1] += cnt[i];
  auto check = [&](int g) {
    for (int i = 0; i <= MAX; i += g) {
      int ub = min(MAX + 1, i + g);
      int lb = i == 0 ? 1 : i + k + 1;
      if (lb <= ub && cnt[ub] - cnt[lb] != 0) return false;
    }
    return true;
  };
  int ans = MAX;
  while (!check(ans)) ans--;
  cout << ans << endl;
  return 0;
}
