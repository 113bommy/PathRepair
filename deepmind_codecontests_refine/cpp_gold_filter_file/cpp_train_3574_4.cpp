#include <bits/stdc++.h>
using namespace std;
int a[500000];
int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  bool pre = 0;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == x) pre = 1;
    v.push_back(a[i]);
  }
  int add = 0;
  int ans = 0;
  if (!pre) {
    ans++;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int l = v.size();
  int mid = v[(l + 1) / 2 - 1];
  if (mid == x) {
    cout << ans << endl;
    return 0;
  } else if (mid > x) {
    add = 1;
  } else
    add = 1000000;
  while (1) {
    int pos = (l + 1) / 2 - 1;
    if (v[pos] == x)
      break;
    else {
      v.push_back(add);
      l++;
      ans++;
    }
    sort(v.begin(), v.end());
  }
  cout << ans << endl;
  return 0;
}
