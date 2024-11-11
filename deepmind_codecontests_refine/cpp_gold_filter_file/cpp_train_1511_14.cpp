#include <bits/stdc++.h>
using namespace std;
int hashh[10000005];
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int arr[n];
  int maxx = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    maxx = max(maxx, arr[i]);
    hashh[arr[i]]++;
  }
  int ans = 0;
  for (int i = 0; i <= 10000000; i++) {
    if (hashh[i]) {
      if (hashh[i] == 1) {
      } else {
        if (hashh[i] % 2) {
          ans++;
          hashh[i]--;
        }
        while (hashh[i]) {
          int xx = log2(hashh[i]);
          hashh[i + xx]++;
          hashh[i] -= pow(2, xx);
        }
      }
    }
  }
  for (int i = 0; i <= 10000000; i++)
    if (hashh[i]) ans++;
  cout << ans << endl;
}
