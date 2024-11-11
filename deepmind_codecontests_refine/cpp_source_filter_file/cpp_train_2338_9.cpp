#include <bits/stdc++.h>
using namespace std;
long long arr[500005], summ[500005], cnt[500005];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % 3)
    cout << 0 << endl;
  else {
    for (int i = n - 1; i > 1; --i) {
      summ[i] = summ[i + 1] + arr[i];
      if (summ[i] == sum / 3)
        cnt[i] = cnt[i + 1] + 1;
      else
        cnt[i] = cnt[i + 1];
    }
    long long temp = 0;
    long long ans = 0;
    for (int i = 0; i < n - 2; ++i) {
      temp += arr[i];
      if (temp == sum / 3) {
        ans = ans + cnt[i + 1];
      }
    }
    cout << ans << endl;
  }
}
