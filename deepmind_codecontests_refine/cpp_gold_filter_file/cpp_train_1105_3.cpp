#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
long long grundy[2 * MAX_N];
vector<int> arr[2 * MAX_N];
bool np[2 * MAX_N];
long long mex(vector<long long> &a) {
  if (a.empty()) {
    return 0;
  }
  sort(a.begin(), a.end());
  if (a[0] != 0) {
    return 0;
  }
  for (int i = 1; i < a.size(); i++) {
    if (a[i] != a[i - 1] + 1 && a[i] != a[i - 1]) {
      return a[i - 1] + 1;
    }
  }
  return a[a.size() - 1] + 1;
}
long long xr[MAX_N];
int main() {
  int n;
  cin >> n;
  grundy[0] = 0;
  for (int i = 2; i * i <= MAX_N; i++) {
    for (int j = i; j <= MAX_N; j += i) {
      np[j] = false;
      if ((j + (i * (i - 1)) / 2)) {
        arr[j + (i * (i - 1)) / 2].push_back(i);
      }
    }
  }
  vector<long long> mexarr;
  long long inf = 22222222222222222, ans;
  for (int i = 1; i <= n; i++) {
    mexarr.clear();
    ans = inf;
    for (int j = 0; j < arr[i].size(); j++) {
      long long curr = i - (arr[i][j] * (arr[i][j] - 1)) / 2;
      long long l = curr / arr[i][j], r = curr / arr[i][j] + arr[i][j] - 1;
      if (l == 0) {
        mexarr.push_back(xr[r]);
      } else {
        mexarr.push_back(xr[r] ^ xr[l - 1]);
      }
      if (mexarr[mexarr.size() - 1] == 0 && ans > arr[i][j]) {
        ans = arr[i][j];
      }
    }
    grundy[i] = mex(mexarr);
    xr[i] = xr[i - 1] ^ grundy[i];
  }
  if (ans == inf) {
    cout << -1;
  } else {
    cout << ans;
  }
  return 0;
}
