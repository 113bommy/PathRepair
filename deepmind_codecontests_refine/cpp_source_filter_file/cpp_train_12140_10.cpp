#include <bits/stdc++.h>
using namespace std;
int cnt[1000001] = {0}, ans[1000001] = {0};
int two[200001];
int main() {
  int n, x, i, j;
  long long int over = 0;
  two[0] = 1;
  for (i = 1; i < 100001; i++) {
    two[i] = 2 * two[i - 1];
    two[i] %= 1000000007;
  }
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  for (i = 2; i < 1000001; i++) {
    for (j = 2 * i; j < 1000001; j += i) {
      cnt[i] += cnt[j];
    }
  }
  for (i = 1000001 - 1; i > 1; i--) {
    over = cnt[i];
    if (over == 0) continue;
    over *= two[cnt[i] - 1];
    over %= 1000000007;
    ans[i] = over;
    for (j = 2 * i; j < 1000001; j += i) {
      ans[i] -= ans[j];
      ans[i] %= 1000000007;
    }
  }
  long long int res = 0;
  for (i = 2; i < 1000001; i++) {
    over = i;
    over *= ans[i];
    over %= 1000000007;
    res += over;
    res %= 1000000007;
  }
  res = (res + 1000000007) % 1000000007;
  cout << res << '\n';
  return 0;
}
