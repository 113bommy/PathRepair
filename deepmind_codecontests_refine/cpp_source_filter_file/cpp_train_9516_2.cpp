#include <bits/stdc++.h>
using namespace std;
long long int vol, digit, ans = 1e9, len;
vector<long long int> arr(11), final_ans(11, 0);
signed main() {
  cin >> vol;
  arr[0] = 0;
  for (int i = 1; i <= 9; i++) {
    cin >> arr[i];
    if (arr[i] < ans) {
      ans = arr[i];
      digit = i;
    }
  }
  len = vol / ans;
  final_ans[digit] = len;
  if (len == 0) {
    cout << -1 << endl;
    return 0;
  }
  vol %= ans;
  for (int i = 9; i > 0; i--) {
    if (i > digit && arr[i] > arr[digit]) {
      final_ans[i] += vol / (arr[i] - arr[digit]);
      final_ans[digit] -= vol / (arr[i] - arr[digit]);
      vol %= (arr[i] - arr[digit]);
    }
  }
  for (int i = 9; i > 0; i--) {
    while (final_ans[i]) {
      cout << i;
      final_ans[i]--;
    }
  }
}
