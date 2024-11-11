#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[1000], n, k, s = 0, c = 0, v = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] <= 8) {
      s = s + arr[i];
      c++;
      if (s == k) break;
    } else if (arr[i] > 8) {
      v = arr[i] - 8;
      arr[i + 1] += v;
      s = s + 8;
      c++;
      if (s == k) break;
    }
  }
  if (s >= k)
    cout << c;
  else
    cout << "-1";
  return 0;
}
