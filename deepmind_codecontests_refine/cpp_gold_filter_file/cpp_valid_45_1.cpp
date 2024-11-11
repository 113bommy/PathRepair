#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    long long int cnt = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] %= 2;
      if (a[i] == 1)
        cnt++;
      else
        cnt--;
    }
    if (cnt < -1 || cnt > 1) {
      cout << -1 << endl;
      continue;
    }
    vector<long long int> b;
    for (long long int i = 0; i < n; i++)
      if (a[i] == 0) b.push_back(i);
    if (cnt == 0) {
      long long int co1 = 0, ans1 = 0, ans2 = 0;
      for (long long int i = 0; i < n; i += 2) {
        if (co1 == b.size()) {
          ans1 = -1;
          break;
        } else {
          ans1 += abs(i - b[co1]);
          co1++;
        }
      }
      co1 = 0;
      for (long long int i = 1; i < n; i += 2) {
        if (co1 == b.size()) {
          ans2 = -1;
          break;
        } else {
          ans2 += abs(i - b[co1]);
          co1++;
        }
      }
      if (ans1 == -1 && ans2 == -1)
        cout << -1 << endl;
      else if (ans1 != -1 && ans2 != -1)
        cout << min(ans1, ans2) << endl;
      else if (ans1 != -1)
        cout << ans1 << endl;
      else
        cout << ans2 << endl;
    } else if (cnt < 0) {
      long long int co1 = 0, ans1 = 0, ans2 = 0;
      for (long long int i = 0; i < n; i += 2) {
        if (co1 == b.size()) {
          ans1 = -1;
          break;
        } else {
          ans1 += abs(i - b[co1]);
          co1++;
        }
      }
      cout << ans1 << endl;
    } else {
      long long int co1 = 0, ans1 = 0, ans2 = 0;
      for (long long int i = 1; i < n; i += 2) {
        if (co1 == b.size()) {
          ans1 = -1;
          break;
        } else {
          ans1 += abs(i - b[co1]);
          co1++;
        }
      }
      cout << ans1 << endl;
    }
  }
}
