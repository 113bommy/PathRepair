#include <bits/stdc++.h>
using namespace std;
long long n, m, x, k, y, a[200005], b[200005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> x >> k >> y;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<long long> contain;
  contain.push_back(-1);
  int index = 0;
  for (int i = 0; i < n && index < m; ++i) {
    if (a[i] == b[index]) {
      contain.push_back(i);
      index++;
    }
  }
  contain.push_back(n);
  if (index < m) {
    cout << -1 << "\n";
    return 0;
  }
  long long res = 0;
  if (x <= k * y) {
    for (int i = 1; i < contain.size(); ++i) {
      long long counter = 0;
      for (int j = contain[i - 1] + 1; j < contain[i]; ++j) {
        if ((contain[i] == n || a[j] > a[contain[i]]) &&
            (contain[i - 1] == -1 || a[j] > a[contain[i - 1]])) {
          if (contain[i] - j >= k) {
            res += x;
            j += (k - 1);
          } else if (contain[i] - j + counter >= k) {
            res += x;
            counter -= (k - contain[i] + j);
            break;
          } else {
            cout << -1 << "\n";
            return 0;
          }
        } else {
          counter++;
        }
      }
      res += (counter / k) * x;
      res += (counter % k) * y;
    }
  } else {
    for (int i = 1; i < contain.size(); ++i) {
      bool large = false;
      for (int j = contain[i - 1] + 1; j < contain[i]; ++j) {
        if ((contain[i] == n || a[j] > a[contain[i]]) &&
            (contain[i - 1] == -1 || a[j] > a[contain[i - 1]])) {
          large = true;
          break;
        }
      }
      long long size = contain[i] - contain[i - 1] - 1;
      if (large) {
        if (size >= k) {
          res += x;
          size -= k;
        } else {
          cout << -1 << "\n";
          return 0;
        }
      }
      res += size * y;
    }
  }
  cout << res << "\n";
  return 0;
}
