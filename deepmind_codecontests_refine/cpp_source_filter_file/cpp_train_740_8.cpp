#include <bits/stdc++.h>
using namespace std;
long long int ll_max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
int int_max(int a, int b, int c) { return max(a, max(b, c)); }
long long int ll_min(long long int a, long long int b, long long int c) {
  return min(a, min(b, c));
}
int int_min(int a, int b, int c) { return min(a, min(b, c)); }
long long int max(int a, long long int b) { return max((long long int)a, b); }
long long int min(int a, long long int b) { return min((long long int)a, b); }
long long int min(long long int a, int b) { return min(a, (long long int)b); }
long long int max(long long int a, int b) { return max(a, (long long int)b); }
long long int maximum(long long int a[], long long int n) {
  long long int max1 = LLONG_MIN;
  for (long long int i = 0; i < n; i++) {
    max1 = max(max1, a[i]);
  }
  return max1;
}
long long int minimum(long long int a[], long long int n) {
  long long int min1 = LLONG_MAX;
  for (long long int i = 0; i < n; i++) {
    min1 = min(min1, a[i]);
  }
  return min1;
}
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int power(long long int x, long long int y, long long int m) {
  if (y == 0) return 1;
  long long int a = power(x, y / 2, m);
  if (y % 2) {
    return (a * ((a * x) % m)) % m;
  } else {
    return (a * a) % m;
  }
}
long long int mod_inverse(long long int x, long long int m) {
  return power(x, m - 2, m);
}
long long int fact(long long int n, long long int m) {
  if (n <= 1) return 1;
  return (fact(n - 1, m) * n) % m;
}
long long int ncr(long long int n, long long int r, long long int m) {
  if (r > n) return 0;
  long long int n1 = 1, d1 = 1, d2 = 1;
  n1 = fact(n, m);
  d1 = fact(r, m);
  d2 = fact(n - r, m);
  long long int ans = mod_inverse((d1 * d2) % m, m);
  ans = (ans * n1) % m;
  return ans;
}
int gcd(int a, int b) {
  if (a == 0 || b == 0) return max(a, b);
  if (a < b) return gcd(b, a);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
int ispal(string s) {
  int len = s.size();
  int flag = 1;
  for (int i = 0; i < len; ++i) {
    if (s[i] != s[len - i - 1]) {
      flag = 0;
      break;
    }
  }
  return flag;
}
long long int sroot(long long int n, long long int low = 1,
                    long long int high = 1e9 + 1) {
  if (low == high) return low;
  if (low == high - 1) {
    if (high * high <= n)
      return high;
    else
      return low;
  }
  long long int mid = (low + high) / 2;
  long long int a = mid * mid;
  if (a > n)
    return sroot(n, low, mid - 1);
  else
    return sroot(n, mid, high);
}
long long int croot(long long int n, long long int low = 1,
                    long long int high = 1e6 + 1) {
  if (low == high) return low;
  if (low == high - 1) {
    if (high * high * high <= n)
      return high;
    else
      return low;
  }
  long long int mid = (low + high) / 2;
  long long int a = mid * mid * mid;
  if (a > n)
    return croot(n, low, mid - 1);
  else
    return croot(n, mid, high);
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
class solver {
 public:
  long long int a[505];
  void even(long long int n) {
    long long int N = n * n;
    long long int cnt[1005]{};
    for (long long int i = 0; i < N; i++) cnt[a[i]]++;
    long long int f = 0, c = 0;
    for (long long int i = 1; i <= 1000; i++) {
      long long int x = cnt[i];
      if (x % 4 != 0) {
        f = 1;
        break;
      }
      c += x / 4;
    }
    if (f == 0 && c == ((n / 2) * (n / 2))) {
      cout << "YES\n";
      long long int n1 = n / 2;
      long long int m[n1 + 1][n1 + 1];
      long long int i = 1, j = 1;
      for (long long int k = 1; k <= 1000; k++) {
        long long int x = cnt[k];
        while (x != 0) {
          m[i][j] = k;
          i++;
          if (i == n1 + 1) {
            i = 1;
            j++;
          }
          x -= 4;
        }
      }
      for (long long int i = 1; i <= n1; i++) {
        for (long long int j = 1; j <= n1; j++) cout << m[i][j] << " ";
        for (long long int j = n1; j >= 1; j--) cout << m[i][j] << " ";
        cout << "\n";
      }
      for (long long int i = n1; i >= 1; i--) {
        for (long long int j = 1; j <= n1; j++) cout << m[i][j] << " ";
        for (long long int j = n1; j >= 1; j--) cout << m[i][j] << " ";
        cout << "\n";
      }
    } else
      cout << "NO";
  }
  void odd(long long int n) {
    long long int N = n * n;
    long long int cnt[1005]{};
    for (long long int i = 0; i < N; i++) cnt[a[i]]++;
    long long int f = 0, c = 0;
    long long int dp[10]{};
    long long int g = (n / 2) * (n / 2);
    vector<long long int> v4;
    vector<long long int> v2, v1;
    for (long long int k = 1; k <= 1000; k++) {
      long long int x = cnt[k];
      if (x % 2 == 1) {
        dp[1]++;
        v1.push_back(k);
        x--;
      }
      while (x != 0) {
        if (x >= 4) {
          if (dp[4] < g) {
            dp[4]++;
            x -= 4;
            v4.push_back(k);
          } else {
            dp[2]++;
            v2.push_back(k);
            x -= 2;
          }
        } else if (x >= 2) {
          dp[2]++, x -= 2;
          v2.push_back(k);
        }
      }
    }
    if (dp[4] == g && dp[1] == 1 && dp[2] == ((n / 2) * 2)) {
      cout << "YES\n";
      long long int n1 = n / 2;
      long long int m[n1 + 1][n1 + 1];
      long long int c = 0;
      long long int i = 1, j = 1;
      for (long long int k = 1; k <= g; k++) {
        m[i][j] = v4[c++];
        i++;
        if (i == (1 + n1)) {
          i = 1;
          j++;
        }
      }
      c = 0;
      vector<long long int> vy;
      for (long long int i = 1; i <= n1; i++) {
        for (long long int j = 1; j <= n1; j++) cout << m[i][j] << " ";
        vy.push_back(v2[c]);
        cout << v2[c++] << " ";
        for (long long int j = n1; j >= 1; j--) cout << m[i][j] << " ";
        cout << "\n";
      }
      vector<long long int> vx;
      for (long long int i = 1; i <= 1; i++) {
        while (c != v2.size()) vx.push_back(v2[c]), cout << v2[c++] << " ";
        if (c == v2.size()) {
          cout << dp[1] << " ";
          for (long long int j = vx.size() - 1; j >= 0; j--)
            cout << vx[j] << " ";
        }
      }
      cout << "\n";
      c = vy.size() - 1;
      for (long long int i = n1; i >= 1; i--) {
        for (long long int j = 1; j <= n1; j++) cout << m[i][j] << " ";
        cout << vy[c--] << " ";
        for (long long int j = n1; j >= 1; j--) cout << m[i][j] << " ";
        cout << "\n";
      }
    } else
      cout << "NO";
  }
  void solve() {
    long long int n;
    cin >> n;
    long long int N = n * n;
    for (long long int i = 0; i < N; i++) cin >> a[i];
    if (n == 1) {
      cout << "YES\n" << a[0];
    } else {
      if (n % 2 == 0)
        even(n);
      else
        odd(n);
    }
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int test = 1, c = 1;
  while (test--) {
    solver o;
    o.solve();
  }
}
