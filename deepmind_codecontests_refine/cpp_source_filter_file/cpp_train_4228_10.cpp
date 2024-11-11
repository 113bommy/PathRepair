#include <bits/stdc++.h>
using namespace std;
int fib[1000];
int main() {
  long long n;
  cin >> n;
  long long v;
  int cnt = 0;
  vector<long long> a, b, c, d;
  int adc[20001], add[20001];
  for (int i = 0; i < n; i++) {
    adc[i] = 0;
    add[i] = 0;
  }
  a.clear();
  b.clear();
  c.clear();
  d.clear();
  int flag = 0, flag2 = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    b.push_back(x);
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      c.push_back(a[i]);
      d.push_back(a[i]);
      adc[a[i]]++;
      add[a[i]]++;
    } else if (a[i] != b[i] and flag == 0) {
      c.push_back(a[i]);
      adc[a[i]]++;
      d.push_back(b[i]);
      add[b[i]]++;
      cnt++;
      v = i;
      flag = 1;
    } else {
      c.push_back(b[i]);
      d.push_back(a[i]);
      adc[b[i]]++;
      add[a[i]]++;
      cnt++;
      v = i;
    }
  }
  if (cnt != 1) {
    for (int i = 0; i <= n; i++) {
      if (adc[i] >= 2) {
        for (int i = 0; i < n; i++) cout << d[i] << " ";
        flag2 = 1;
        break;
      }
    }
    if (flag2 != 1) {
      for (int i = 0; i < n; i++) cout << c[i] << " ";
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (adc[i] == 0) {
        c[v] = i;
      }
    }
    for (int i = 0; i < n; i++) cout << c[i] << " ";
  }
}
