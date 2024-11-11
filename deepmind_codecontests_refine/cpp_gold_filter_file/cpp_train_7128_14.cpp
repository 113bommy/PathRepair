#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
long long Max(long long a, long long b) { return a > b ? a : b; }
long long Min(long long a, long long b) { return a < b ? a : b; }
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, z, r, s, i, j, flag = 0;
  cin >> n >> m;
  vector<string> arr(n);
  for (long long o = 0; o < n; o++) {
    cin >> arr[o];
  }
  queue<pair<long long, long long> > q;
  for (long long o = 0; o < n; o++) {
    for (long long p = 0; p < m; p++) {
      i = o, j = p, z = 0;
      if (arr[i][j] == '.') {
        flag = 1;
        if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
        if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
        if (i + 1 < n && arr[i + 1][j] == '.') z++;
        if (j + 1 < m && arr[i][j + 1] == '.') z++;
      }
      if (z == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  if (q.empty() == true && flag == 1) {
    cout << "Not unique";
    return 0;
  } else {
    while (q.empty() != true) {
      r = q.front().first;
      s = q.front().second;
      q.pop();
      if (arr[r][s] == '.') {
        if (r - 1 >= 0 && arr[r - 1][s] == '.') {
          arr[r - 1][s] = '^';
          arr[r][s] = 'v';
          z = 0;
          i = r - 2, j = s;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r - 1, j = s - 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r - 1, j = s + 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
        }
        if (s - 1 >= 0 && arr[r][s - 1] == '.') {
          arr[r][s - 1] = '<';
          arr[r][s] = '>';
          z = 0;
          i = r - 1, j = s - 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r + 1, j = s - 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r, j = s - 2;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
        }
        if (r + 1 < n && arr[r + 1][s] == '.') {
          arr[r + 1][s] = 'v';
          arr[r][s] = '^';
          z = 0;
          i = r + 2, j = s;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r + 1, j = s - 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r + 1, j = s + 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
        }
        if (s + 1 < m && arr[r][s + 1] == '.') {
          arr[r][s + 1] = '>';
          arr[r][s] = '<';
          z = 0;
          i = r, j = s + 2;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r + 1, j = s + 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
          z = 0;
          i = r - 1, j = s + 1;
          if (i >= 0 && i < n && j >= 0 && j < m && arr[i][j] == '.') {
            if (i - 1 >= 0 && arr[i - 1][j] == '.') z++;
            if (j - 1 >= 0 && arr[i][j - 1] == '.') z++;
            if (i + 1 < n && arr[i + 1][j] == '.') z++;
            if (j + 1 < m && arr[i][j + 1] == '.') z++;
          }
          if (z == 1) {
            q.push(make_pair(i, j));
          }
        }
      }
    }
    for (long long o = 0; o < n; o++) {
      for (long long p = 0; p < m; p++) {
        if (arr[o][p] == '.') {
          cout << "Not unique";
          return 0;
        }
      }
    }
    for (long long o = 0; o < n; o++) {
      for (long long p = 0; p < m; p++) {
        cout << arr[o][p];
      }
      cout << endl;
    }
  }
  return 0;
}
