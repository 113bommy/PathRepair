#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, k, num[101];
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < k; i++) num[i] = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    num[a % k]++;
  }
  long long int cnt = num[0] / 2;
  if (k % 2 == 0) {
    cnt += (num[k / 2] / 2);
    for (int i = 1; i < k / 2; i++) {
      cnt += min(num[i], num[k - i]);
    }
  } else {
    for (int i = 1; i <= k / 2; i++) {
      cnt += min(num[i], num[k - i]);
    }
  }
  cout << cnt * 2 << endl;
  return 0;
}
