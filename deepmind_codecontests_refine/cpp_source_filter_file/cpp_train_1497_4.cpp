#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, d;
  cin >> n >> d;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  int i = 0;
  long long ans = 0;
  for (int j = 2; j < n; j++) {
    while (arr[j] - arr[i] > d) {
      i++;
    }
    if (j - i + 1 < 3) {
      continue;
    }
    int count = j - i + 1;
    ans += (((count - 1) * (count - 2)) / 2);
  }
  cout << ans << endl;
  return 0;
}
