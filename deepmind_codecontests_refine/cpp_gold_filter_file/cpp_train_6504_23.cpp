#include <bits/stdc++.h>
using namespace std;
int arr[1 << 13], n;
long long ans = 0;
int main() {
  cin >> n;
  n++;
  arr[1] = 0;
  for (int i = 2; i < (1 << n); i++) cin >> arr[i];
  for (int i = (1 << n) - 2; i >= 2; i -= 2) {
    ans += abs(arr[i] - arr[i + 1]);
    arr[i / 2] += max(arr[i], arr[i + 1]);
  }
  cout << ans << "\n";
  return 0;
}
