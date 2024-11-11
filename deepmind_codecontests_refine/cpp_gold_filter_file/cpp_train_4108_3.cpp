#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int64_t> freq(100003, 0);
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    freq[arr[i]]++;
  }
  vector<int64_t> sum(1000005, 0);
  sum[1] = freq[1];
  for (int i = 2; i <= 100000; i++) {
    sum[i] = max(sum[i - 2] + freq[i] * i, sum[i - 1]);
  }
  cout << sum[100000] << endl;
  return 0;
}
