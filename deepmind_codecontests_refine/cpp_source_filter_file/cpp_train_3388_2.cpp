#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long mod = 1e9 + 7;
int main() {
  fast();
  long long n, k;
  cin >> n >> k;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long l = 0, r = 0;
  long long j = 0, cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (j < i) {
      j = i;
      cnt = 0;
    }
    while (j < n) {
      long long cur = cnt + !arr[j];
      if (cur > k) break;
      cnt += !arr[j];
      j++;
    }
    if (j - i > r - l) l = i, r = j;
    if (cnt > 0) cnt -= !arr[i];
  }
  cout << r - l << "\n";
  for (long long i = 0; i < n; i++) {
    if (i >= l && i <= j)
      cout << "1 ";
    else
      cout << arr[i] << " ";
  }
}
