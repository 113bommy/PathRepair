#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 'C' << ' ' << n << endl;
    return 0;
  }
  vector<long long> a(n + 1, 1);
  vector<long long> b(n + 1, 1);
  vector<long long> sum(n + 1);
  vector<long long> p;
  for (int i = 2; i < n + 1; i++) {
    if (a[i]) {
      p.push_back(i);
      for (int j = i; j <= n; j += i) {
        sum[i] += a[j];
        a[j] = 0;
      }
    }
  }
  int cur = 1;
  int low = 0;
  int count = n;
  while (low < p.size()) {
    int mid = (low + p.size() + 1) / 2;
    if (low == 0) {
      mid = min(mid, 100);
    }
    for (int i = low; i < mid; i++) {
      cout << 'B' << ' ' << p[i] << endl;
      long long x;
      cin >> x;
      for (int j = p[i]; j <= n; j += p[i]) {
        b[j] = 0;
      }
      count -= x;
    }
    cout << 'A' << ' ' << 1 << endl;
    long long x;
    cin >> x;
    if (x > count) {
      if (low == 0) {
        mid = p.size();
      }
      for (int i = low; i < mid; i++) {
        long long pp = p[i];
        cout << 'A' << ' ' << pp << endl;
        long long x;
        cin >> x;
        int supposed = 0;
        for (int j = pp; j <= n; j += pp) {
          supposed += b[j];
        }
        while (x > supposed) {
          cur *= p[i];
          pp *= p[i];
          if (pp > n) {
            break;
          }
          cout << 'A' << ' ' << pp << endl;
          supposed = 0;
          for (int j = pp; j <= n; j += pp) {
            supposed += b[j];
          }
          cin >> x;
        }
      }
      break;
    } else {
      low = mid;
    }
  }
  cout << 'C' << ' ' << cur << endl;
  return 0;
  return 0;
}
