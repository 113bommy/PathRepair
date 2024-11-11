#include <bits/stdc++.h>
using namespace std;
int cnt[200001][2];
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  for (long long i = 1; i <= b.size(); i++) {
    cnt[i][0] = cnt[i - 1][0] + (b[i - 1] == '0');
    cnt[i][1] = cnt[i - 1][1] + (b[i - 1] == '1');
  }
  long long ans = 0;
  for (long long i = 0; i < a.size(); i++) {
    int x = a.size();
    int y = b.size();
    if (a[i] == '0') {
      ans += cnt[y - x + i + 1][1] - cnt[i][1];
    } else {
      ans += cnt[y - x + i + 1][0] - cnt[i][0];
    }
  }
  cout << ans;
  return 0;
}
