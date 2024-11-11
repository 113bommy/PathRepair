#include <bits/stdc++.h>
using namespace std;
int arr[5050], d[1000005], mod[1000005], n, k, mx, cnt, tot;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  mx = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      d[arr[j] - arr[i]]++;
      mx = max(mx, arr[j] - arr[i]);
    }
  }
  for (int i = n - k;; i++) {
    tot = 0;
    for (int j = i; j <= mx; j += i) tot += d[j];
    if (tot > k * (k + 1) / 2) continue;
    cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (mod[arr[j] % i] == i) cnt++;
      mod[arr[j] % i] = i;
    }
    if (cnt <= k) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
