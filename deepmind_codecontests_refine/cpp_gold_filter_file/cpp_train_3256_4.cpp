#include <bits/stdc++.h>
using namespace std;
void royale_paradox() {
  long long int arr[1000002] = {0};
  vector<long long int> p;
  long long int x = 1000002;
  for (long long int j = 2; j * j <= x; j++) {
    if (arr[j] == 0)
      for (long long int i = j * j; i <= x; i += j) {
        arr[i] = 1;
      }
  }
  long long int c = 0;
  for (long long int i = 1; i <= x; i++) {
    if (arr[i] == 0) {
      c++;
      p.push_back(i);
    }
    arr[i] = c;
  }
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int x, ans = 0;
    cin >> x;
    long long int k = p[1];
    long long int j = 1;
    while (p[j] * p[j] <= x) {
      ans++;
      j++;
    }
    cout << arr[x] - ans << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int TEST;
  TEST = 1;
  while (TEST--) {
    royale_paradox();
  }
  return 0;
}
