#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 2e18;
const double pi = 3.1415926535898;
long long binpow(long long a, long long n) {
  if (n == 0) {
    return 1;
  }
  long long res = 1;
  while (n) {
    if (n % 2 == 1) {
      res *= a;
    }
    a *= a;
    n /= 2;
  }
  return res;
}
int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
const double EPS = 1e-7;
int siz(long long x) {
  if (x < 1e1) {
    return 1;
  } else if (x < 1e2) {
    return 2;
  } else if (x < 1e3) {
    return 3;
  } else if (x < 1e4) {
    return 4;
  } else if (x < 1e5) {
    return 5;
  } else if (x < 1e6) {
    return 6;
  } else if (x < 1e7) {
    return 7;
  } else if (x < 1e8) {
    return 8;
  } else if (x < 1e9) {
    return 9;
  } else if (x < 1e10) {
    return 10;
  }
}
int n, m, k;
vector<pair<int, int> > sensors;
vector<int> ans;
unordered_map<int, vector<int> > sums, difs;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  sensors.resize(k);
  ans.resize(k);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    sensors[i] = make_pair(x, y);
    ans[i] = -1;
  }
  for (int i = 0; i < k; i++) {
    sums[sensors[i].first + sensors[i].second].push_back(i);
    difs[sensors[i].first - sensors[i].second].push_back(i);
  }
  int x0 = 0, y0 = 0, dir = 0;
  long long dist = 0;
  while (1) {
    if (dir == 0) {
      int dif = x0 - y0;
      if (difs[dif].size() != 0) {
        for (int i = 0; i < difs[dif].size(); i++) {
          int index = difs[dif][i];
          if (ans[index] == -1) {
            ans[index] = dist + abs(x0 - sensors[index].first);
          }
        }
      }
      int small = min(m - y0, n - x0);
      x0 += small;
      y0 += small;
      dist += small;
      if ((x0 == n && y0 == m) || (x0 == 0 && y0 == m) ||
          (x0 == n && y0 == 0) || (x0 == 0 && y0 == 0)) {
        break;
      }
      if (x0 == n) {
        dir = 2;
      } else {
        dir = 3;
      }
    } else if (dir == 1) {
      int dif = x0 - y0;
      if (difs[dif].size() != 0) {
        for (int i = 0; i < difs[dif].size(); i++) {
          int index = difs[dif][i];
          if (ans[index] == -1) {
            ans[index] = dist + abs(x0 - sensors[index].first);
          }
        }
      }
      int small = min(y0, x0);
      x0 -= small;
      y0 -= small;
      dist += small;
      if ((x0 == n && y0 == m) || (x0 == 0 && y0 == m) ||
          (x0 == n && y0 == 0) || (x0 == 0 && y0 == 0)) {
        break;
      }
      if (x0 == 0) {
        dir = 3;
      } else {
        dir = 2;
      }
    } else if (dir == 2) {
      int sum = x0 + y0;
      if (sums[sum].size() != 0) {
        for (int i = 0; i < sums[sum].size(); i++) {
          int index = sums[sum][i];
          if (ans[index] == -1) {
            ans[index] = dist + abs(x0 - sensors[index].first);
          }
        }
      }
      int small = min(m - y0, x0);
      x0 -= small;
      y0 += small;
      dist += small;
      if ((x0 == n && y0 == m) || (x0 == 0 && y0 == m) ||
          (x0 == n && y0 == 0) || (x0 == 0 && y0 == 0)) {
        break;
      }
      if (x0 == 0) {
        dir = 0;
      } else {
        dir = 1;
      }
    } else if (dir == 3) {
      int sum = x0 + y0;
      if (sums[sum].size() != 0) {
        for (int i = 0; i < sums[sum].size(); i++) {
          int index = sums[sum][i];
          if (ans[index] == -1) {
            ans[index] = dist + abs(x0 - sensors[index].first);
          }
        }
      }
      int small = min(y0, n - x0);
      x0 += small;
      y0 -= small;
      dist += small;
      if ((x0 == n && y0 == m) || (x0 == 0 && y0 == m) ||
          (x0 == n && y0 == 0) || (x0 == 0 && y0 == 0)) {
        break;
      }
      if (x0 == n) {
        dir = 1;
      } else {
        dir = 0;
      }
    }
  }
  for (int i = 0; i < k; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
