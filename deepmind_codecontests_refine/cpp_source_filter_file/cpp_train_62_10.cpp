#include <bits/stdc++.h>
using namespace std;
using ll = signed long long int;
const int N = 1e5 + 100;
int n, res;
ll mx[N], a[N], d, cv;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n && res != -1; i++) {
    if (a[i] == 0) {
      cv = 0LL;
    } else {
      cv += a[i];
      if (cv > d) {
        res = -1;
      }
    }
  }
  if (res != -1) {
    mx[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      mx[i] = max(mx[i + 1] + a[i], a[i]);
    }
    cv = 0LL;
    for (int i = 0; i < n; i++) {
      cv += a[i];
      if (a[i] == 0LL) {
        if (cv < 0LL) {
          res++;
          cv = d - mx[i];
        }
      }
    }
  }
  cout << res;
}
