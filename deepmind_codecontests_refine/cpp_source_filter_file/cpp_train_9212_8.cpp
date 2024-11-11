#include <bits/stdc++.h>
using namespace std;
long long modInverse(long long a, long long m);
long long power(long long x, unsigned long long y, unsigned long long m);
long long logint(long long x, long long y);
long long power(long long x, unsigned long long y, unsigned long long m) {
  if (y == 0) return 1;
  long long p = power(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long modInverse(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long logint(long long x, long long y) {
  long long ans = 0;
  long long a = 1;
  for (long long i = 0; i < x; i++) {
    if (x <= a) {
      return ans;
    }
    ans++;
    a *= y;
  }
  return -1;
}
int bin(long long ar[], long long left, long long right) {
  long long ans = 1000000000;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    if (ar[mid] == 0) {
      left = mid + 1;
    } else {
      ans = min(ans, mid);
      right = mid - 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<pair<long long, pair<long long, long long> > > ar(0);
  long long ans = 0;
  for (long long i = 0; i < 3; i++) {
    long long a, b;
    cin >> a >> b;
    ans += a * b;
    long long t = max(a, b);
    b = min(a, b);
    a = t;
    ar.push_back(make_pair(a, make_pair(b, i)));
  }
  sort(ar.begin(), ar.end());
  reverse(ar.begin(), ar.end());
  long long n = ar[0].first;
  if (n * n != ans) {
    cout << "-1";
    return 0;
  }
  long long z = ar[0].second.first;
  char aa[n][n];
  for (long long i = 0; i < z; i++) {
    for (long long j = 0; j < n; j++) {
      aa[i][j] = 'A' + ar[0].second.second;
    }
  }
  int f = 0;
  long long p, q;
  p = ar[2].first;
  q = ar[2].second.first;
  if (n == ar[1].first && n == ar[2].first) {
    for (int i = z; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i < z + ar[1].second.first) {
          aa[i][j] = 'A' + ar[1].second.second;
        } else {
          aa[i][j] = ar[2].second.second + 'A';
        }
      }
    }
  } else if (n - z == ar[1].first) {
    long long y = ar[1].second.first;
    long long x = ar[1].first;
    if ((x == p && n - y == q) || (x == q && n - y == p)) {
      for (int i = z; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (j < y) {
            aa[i][j] = 'A' + ar[1].second.second;
          } else {
            aa[i][j] = ar[2].second.second + 'A';
          }
        }
      }
    } else {
      f = 1;
    }
  } else if (n - z == ar[1].second.first) {
    long long y = ar[1].first;
    long long x = ar[1].second.first;
    if ((x == p && n - y == q) || (x == q && n - y == p)) {
      for (int i = z; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (j < x) {
            aa[i][j] = 'A' + ar[1].second.second;
          } else {
            aa[i][j] = ar[2].second.second + 'A';
          }
        }
      }
    } else {
      f = 1;
    }
  } else {
    cout << "-1";
    return 0;
  }
  if (f) {
    cout << "-1";
  } else {
    cout << n << endl;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        cout << aa[i][j];
      }
      cout << endl;
    }
  }
}
