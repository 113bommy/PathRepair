#include <bits/stdc++.h>
using namespace std;
long long int pre[200003];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int sy, a, b;
  cin >> sy >> a >> b;
  long long int n;
  cin >> n;
  vector<array<long long int, 2>> v;
  for (long long int i = 0; i < n; i++) {
    long long int l, r;
    cin >> l >> r;
    v.push_back({l, r});
  }
  for (long long int i = 0; i < n; i++) {
    pre[i + 1ll] = pre[i] + v[i][1] - v[i][0];
  }
  long long int q;
  cin >> q;
  double ans;
  while (q--) {
    long long int x, y;
    cin >> x >> y;
    double xs, xe, m;
    long long int indxs, indxe;
    if (x == a) {
      xs = x;
    } else {
      m = (y - sy) / (double)(x - a);
      xs = (m * x - y) / m;
    }
    long long int lo = 0;
    long long int hi = n - 1ll;
    long long int indx = -1ll;
    while (lo <= hi) {
      long long int mid = (lo + hi) / 2;
      if (v[mid][0] <= xs && xs <= v[mid][1]) {
        indx = mid;
        break;
      } else if (xs < v[mid][0]) {
        hi = mid - 1ll;
      } else {
        lo = mid + 1ll;
      }
    }
    if (indx == -1) {
      long long int lo = 0;
      long long int hi = n - 1ll;
      while (lo <= hi) {
        long long int mid = (lo + hi) / 2;
        if (v[mid][0] >= xs) {
          indx = mid;
          hi = mid - 1ll;
        } else {
          lo = mid + 1ll;
        }
      }
      if (indx != -1ll) {
        xs = v[indx][0];
        ans = v[indx][1] - v[indx][0];
        indxs = indx;
        double z;
        if (x == xs) {
          z = x;
        } else {
          m = y / (x - xs);
          z = (sy / m) + xs;
        }
        if (z > b) {
          ans = 0;
          cout << fixed << setprecision(10) << ans << "\n";
          continue;
        }
      } else {
        ans = 0;
        cout << fixed << setprecision(10) << ans << "\n";
        continue;
      }
    } else {
      indxs = indx;
      ans = v[indx][1] - xs;
    }
    if (x == b) {
      xe = x;
    } else {
      m = (y - sy) / (double)(x - b);
      xe = (m * x - y) / m;
    }
    lo = 0;
    hi = n - 1ll;
    indx = -1ll;
    while (lo <= hi) {
      long long int mid = (lo + hi) / 2;
      if (v[mid][0] <= xe && xe <= v[mid][1]) {
        indx = mid;
        break;
      } else if (xe < v[mid][0]) {
        hi = mid - 1ll;
      } else {
        lo = mid + 1ll;
      }
    }
    if (indx == -1) {
      lo = 0;
      hi = n - 1ll;
      indx = -1ll;
      while (lo <= hi) {
        long long int mid = (lo + hi) / 2;
        if (v[mid][1] >= xe) {
          indx = mid;
          hi = mid - 1ll;
        } else {
          lo = mid + 1ll;
        }
      }
      if (indx != -1ll) {
        xe = v[indx][1];
        indxe = indx;
        ans += v[indx][1] - v[indx][0];
        double z;
        if (x == xe) {
          z = x;
        } else {
          m = y / (x - xe);
          z = (sy / m) + xs;
        }
        if (z < a) {
          ans = 0;
          cout << fixed << setprecision(10) << ans << "\n";
          continue;
        }
      } else {
        ans = 0;
        cout << fixed << setprecision(10) << ans << "\n";
        continue;
      }
    } else {
      indxe = indx;
      ans += xe - v[indx][0];
    }
    if (indxs == indxe) {
      ans = xe - xs;
    } else {
      ans += pre[indxe] - pre[indxs + 1ll];
    }
    double mult = (y - sy) / (double)y;
    ans = ans * mult;
    cout << fixed << setprecision(10) << ans << "\n";
  }
}
