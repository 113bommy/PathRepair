#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e8 + 7, N = 3e6 + 5;
int n, m, c;
vector<int> arr;
bool check() {
  int cnt = (arr[0] == 0);
  bool ans = true;
  for (int i = 1; i < n; i++) {
    cnt += (arr[i] == 0);
    if (arr[i - 1] > arr[i]) {
      ans = false;
    }
  }
  if (cnt > 0) {
    ans = false;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> c;
  arr.resize(n);
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    if (k <= c / 2) {
      int ind = 0;
      while (ind < n - 1 && arr[ind] <= k && arr[ind] != 0) {
        ind++;
      }
      arr[ind] = k;
      cout << ind + 1 << endl;
    } else {
      int ind = n - 1;
      while (ind > 0 && arr[ind] >= k && arr[ind] != 0) {
        ind--;
      }
      arr[ind] = k;
      cout << ind + 1 << endl;
    }
    if (check()) {
      return 0;
    }
  }
}
