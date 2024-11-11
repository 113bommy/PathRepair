#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, k, d;
    map<int, int> dict;
    cin >> n >> k >> d;
    vector<int> a(n);
    int coun = 0;
    for (int j = 0; j < d; j++) {
      cin >> a[j];
      dict[a[j]]++;
      if (dict[a[j]] == 1) coun++;
    }
    int minn = coun;
    for (int j = d; j < n; j++) {
      cin >> a[j];
      dict[a[j]]++;
      if (dict[a[j]] == 1) coun++;
      dict[a[j - d]]--;
      if (dict[a[j]] == 0) coun--;
      minn = min(minn, coun);
    }
    cout << minn << '\n';
  }
  return 0;
}
