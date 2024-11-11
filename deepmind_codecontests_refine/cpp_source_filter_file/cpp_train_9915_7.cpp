#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, l, b = 0, left;
    cin >> n >> k;
    vector<int> v;
    bool arr[n];
    int cnt[n];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    for (int i = 1; i < n - 1; i++) {
      if (v[i] > v[i - 1] && v[i] > v[i + 1]) arr[i] = 1;
    }
    cnt[0] = 0;
    for (int i = 1; i < n; i++) {
      cnt[i] = cnt[i - 1] + arr[i];
    }
    for (int i = 0; i <= n - k; i++) {
      l = cnt[i + k - 1] - cnt[i];
      if (arr[i + k - 1]) l--;
      if (arr[i]) l--;
      if (b < l) {
        left = i;
        b = l;
      }
    }
    cout << b + 1 << " " << left + 1 << "\n";
  }
}
