#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
long long v[N];
long long l[N];
long long r[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long res = 1;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (i && v[i - 1] < v[i]) {
      cnt++;
    } else {
      cnt = 1;
    }
    l[i] = cnt;
    if (i != n - 1) {
      res = max(res, l[i] + 1);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1 && v[i + 1] > v[i]) {
      cnt++;
    } else {
      cnt = 1;
    }
    r[i] = cnt;
    if (i - 2 >= 0 && v[i - 2] + 1 < v[i]) {
      res = max(res, l[i - 2] + r[i] + 1LL);
    }
    if (i != 0) {
      res = max(res, r[i] + 1);
    }
  }
  cout << res;
}
