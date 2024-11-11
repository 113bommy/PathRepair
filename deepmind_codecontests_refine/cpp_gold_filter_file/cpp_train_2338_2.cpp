#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int *arr = new int[n];
  ;
  long long sum = 0;
  vector<long long> pre;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    pre.push_back(sum);
  }
  if ((sum % 3) or (n < 3)) {
    cout << 0 << endl;
  } else {
    long long x = sum / 3;
    long long cnt = 0;
    long long total = 0;
    for (int i = 0; i < pre.size() - 1; i++) {
      if (pre[i] == (2 * x)) {
        total += cnt;
      }
      if (pre[i] == x) {
        cnt++;
      }
    }
    cout << total << endl;
  }
  return 0;
}
