#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, num, cnt = 0, cnt1 = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num <= k)
      cnt1++;
    else {
      cnt += num / (k * 2);
      int rem = num % (k * 2);
      if (rem > k)
        cnt++;
      else if (rem < k && rem > 0)
        cnt1++;
    }
  }
  cnt += cnt1 / 2;
  if (cnt1 % 2) cnt++;
  cout << cnt << endl;
}
