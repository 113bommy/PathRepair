#include <bits/stdc++.h>
using namespace std;
int cnt[100];
int main() {
  int n, k, cnt1, curans;
  curans = 0;
  cnt1 = 0;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> cnt[i];
    sum += cnt[i];
  }
  if (n * 8 < k) {
    cout << "-1";
    return 0;
  }
  if (sum < k) {
    cout << "-1";
    return 0;
  }
  int i = 0;
  while (cnt1 < k) {
    if (cnt[i] <= 8) {
      cnt1 += cnt[i];
      curans++;
    } else if (cnt[i] > 8 && i + 1 != n) {
      cnt[i + 1] += cnt[i] - 8;
      cnt1 += 8;
      curans++;
    } else {
      cnt1 += 8;
      curans++;
    }
    if (cnt1 >= k) {
      cout << curans << endl;
      return 0;
    }
    i++;
    if (cnt1 < k && i == n) {
      cout << "-1";
      return 0;
    }
  }
}
