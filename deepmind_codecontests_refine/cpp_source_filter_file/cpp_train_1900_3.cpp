#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[100001];
int test;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] == k) ok = true;
    }
    if (!ok) {
      cout << "no" << '\n';
      continue;
    }
    if (n == 1) {
      cout << "yes" << '\n';
      continue;
    }
    ok = false;
    a[0] = 0, a[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == k && a[i - 1] >= k) ok = true;
      if (a[i] == k && a[i + 1] >= k) ok = true;
    }
    for (int i = 2; i <= n + 1; i++) {
      if (a[i] == k && a[i - 1] >= k) {
        ok = true;
        break;
      }
      vector<long long> tmp;
      for (int j = i; j >= i - 2; j--) tmp.push_back(a[j]);
      sort(tmp.begin(), tmp.end());
      if (tmp[1] >= k) {
        ok = true;
        break;
      }
      if (tmp[1] == k) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "no" << '\n';
    } else
      cout << "yes" << '\n';
  }
  return 0;
}
