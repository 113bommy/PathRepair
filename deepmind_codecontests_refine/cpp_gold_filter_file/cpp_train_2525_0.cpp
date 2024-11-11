#include <bits/stdc++.h>
using namespace std;
long long a[300001];
long long n, k, l;
bool go(int s, int i) {
  long long state = k - 1;
  bool ff = false;
  for (int j = s + 1; j < i; j++) {
    if (a[j] > l) {
      return false;
    }
    if (!ff) {
      if (a[j] + state > l) {
        state = state - ((a[j] + state) - l);
      }
      state -= 1;
      if (state < -1) {
        ff = true;
        state = 0;
        j -= 1;
        continue;
      }
      if (state == -1) {
        ff = true;
        state = 1;
      }
      if (state <= 0) {
        ff = true;
      }
    } else {
      if (a[j] + state > l) {
        return false;
      }
      state += 1;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long s = 0;
    bool f = false;
    for (int i = 1; i <= n; i++) {
      if (a[i] + k <= l) {
        if (!go(s, i)) {
          f = true;
          break;
        }
        s = i;
      }
    }
    if (f) {
      cout << "No" << '\n';
    } else {
      if (go(s, n + 1))
        cout << "Yes" << '\n';
      else
        cout << "No" << '\n';
    }
  }
}
