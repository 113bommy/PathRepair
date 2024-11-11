#include <bits/stdc++.h>
using namespace std;
int cnt[(1000 + 10)];
int main() {
  ios::sync_with_stdio(false);
  int n, A, B, C, T;
  cin >> n >> A >> B >> C >> T;
  if (C <= B) {
    cout << n * A << endl;
    return 0;
  }
  memset(cnt, 0x0, sizeof(cnt));
  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    cnt[tmp]++;
  }
  int ans = n * A;
  const int dlt = C - B;
  for (int i = 0; i <= T; i++) {
    ans += dlt * (i - 1) * cnt[i];
  }
  cout << ans << endl;
  return 0;
}
