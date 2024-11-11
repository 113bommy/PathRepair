#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  bool good = true;
  for (int i = 1; i < n; ++i) {
    if (a[i - 1] == 1 || a[i] >= a[i - 1] * 2) {
    } else {
      good = false;
      break;
    }
  }
  if (good)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
