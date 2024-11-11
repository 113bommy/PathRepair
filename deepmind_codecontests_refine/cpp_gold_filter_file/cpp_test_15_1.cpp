#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a >= b) {
    return a;
  }
  return b;
}
long long min(long long a, long long b) {
  if (a <= b) {
    return a;
  }
  return b;
}
long long modpower(long long a, long long n, long long d = 1000000007) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = ((res % d) * (a % d)) % d;
      n--;
    } else {
      a = ((a % d) * (a % d)) % d;
      n /= 2;
    }
  }
  return res;
}
long long modadd(long long a, long long b, long long d = 1000000007) {
  return ((a % d) + (b % d)) % d;
}
long long modsubtract(long long a, long long b, long long d = 1000000007) {
  return ((a % d) - (b % d)) % d;
}
long long modproduct(long long a, long long b, long long d = 1000000007) {
  return ((a % d) * (b % d)) % d;
}
long long n, m, k;
long long up(long long i, long long j, vector<vector<char>> &input) {
  long long r = i - 1;
  long long c = j + 1;
  long long ct = 0;
  while (r >= 0 && c < m && input[r][c] != '.') {
    ct++;
    r--;
    c++;
  }
  return ct >= k ? ct : 0;
}
void fill(long long i, long long j, long long total,
          vector<vector<char>> &input) {
  long long r = i;
  long long c1 = j;
  long long c2 = j;
  while (total) {
    total--;
    input[r][c1] = '#';
    input[r][c2] = '#';
    r--;
    c1--;
    c2++;
  }
}
void down(long long i, long long j, vector<vector<char>> &input) {
  long long r = i + 1;
  long long c = j + 1;
  long long ct = 0;
  while (r < n && c < m && input[r][c] != '.') {
    ct++;
    if (ct >= k) {
      long long small = up(r, c, input);
      fill(r, c, 1 + min(small, ct), input);
    }
    r++;
    c++;
  }
}
void solve() {
  cin >> n >> m >> k;
  vector<vector<char>> input(n, vector<char>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> input[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (input[i][j] != '.') {
        down(i, j, input);
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (input[i][j] == '*') {
        cout << "NO \n";
        return;
      }
    }
  }
  cout << "YES \n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
