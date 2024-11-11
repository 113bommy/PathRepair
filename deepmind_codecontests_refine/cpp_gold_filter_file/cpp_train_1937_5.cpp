#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stable_sort(a.begin(), a.end());
  long long cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[2]) cnt++;
  }
  if (a[0] == a[2]) {
    cout << (cnt - 2) * (cnt - 1) * cnt / 6;
  } else if (a[1] == a[2]) {
    cout << (cnt - 1) * cnt / 2;
  } else
    cout << cnt;
  return (0);
}
