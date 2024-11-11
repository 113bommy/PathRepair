#include <bits/stdc++.h>
using namespace std;
int a[(int)2e5];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int cur = 0;
  long long ans = 0;
  vector<int> p;
  for (int i = 1; i <= n; i++) {
    if (a[i] < cur) {
      ans += cur - a[i] - 1;
      p.push_back(i);
      continue;
    }
    if (a[i] == cur) {
      cur++;
      continue;
    }
    if (a[i] > cur) {
      int k = a[i] - cur;
      for (int j = 0; j < k; j++) {
        int t = p.back();
        ans += (i - t);
        p.pop_back();
      }
      cur = a[i] + 1;
    }
  }
  cout << ans;
}
