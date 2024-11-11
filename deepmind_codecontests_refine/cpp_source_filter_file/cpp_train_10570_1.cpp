#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[10005], r, l, ans;
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  l = r = 0;
  ans = r = accumulate(arr, arr + N, r);
  for (int i = 0; i < N; i++) {
    r -= arr[i];
    l += arr[i];
    ans = min(ans, abs(r - l));
  }
  cout << ans + 1 << endl;
}
