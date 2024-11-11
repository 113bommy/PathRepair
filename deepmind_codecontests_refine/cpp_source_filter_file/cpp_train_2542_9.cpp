#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> arr;
void mymain() {
  cin >> n;
  arr.resize(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  long long taken = 0;
  long long cnt = 0;
  while (taken != n) {
    long long sz = 0;
    long long lst = -1;
    for (long long i = 0; i < n; i++) {
      if (arr[i] == -1) continue;
      if (arr[i] > lst) {
        sz++;
        taken++;
        if (lst == -1) cnt++;
        lst = arr[i];
        arr[i] = -1;
      }
    }
  }
  cout << cnt << '\n';
}
signed main() {
  long long t = 1;
  for (long long tt = 0; tt < t; tt++) {
    mymain();
  }
  return 0;
}
