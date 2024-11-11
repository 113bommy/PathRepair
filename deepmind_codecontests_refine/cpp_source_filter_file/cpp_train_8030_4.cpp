#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool posibil = true;
  int ans = 1, arr[n];
  for (int c = 0; c < n - 1; c++) {
    int val;
    cin >> val;
    ans += val;
    if (ans <= 0) {
      ans = 1;
    } else if (ans > n)
      posibil = false;
    if (val == 0) posibil = false;
    arr[c] = val;
  }
  map<int, int> m;
  vector<int> a;
  a.push_back(ans);
  m[ans]++;
  for (int c = n - 2; c >= 0; c--) {
    a.push_back(ans - arr[c]);
    ans -= arr[c];
    if (ans > n || ans <= 0) posibil = false;
    m[ans]++;
    if (m[ans] > 0) posibil = false;
  }
  if (posibil)
    for (int c = n - 1; c >= 0; c--) cout << a[c] << ' ';
  if (!posibil) cout << "-1";
  return 0;
}
