#include <bits/stdc++.h>
using namespace std;
long long hug(long long s) {
  long long x = (s * (s + 1)) / 2;
  return x;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    vector<int> v;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 2) {
      cout << 2 << endl << a[0] << " " << a[1] << endl;
      continue;
    }
    long long f;
    if (a[1] > a[0])
      f = 1;
    else
      f = 0;
    v.push_back(a[0]);
    for (int i = 2; i < n; i++) {
      if (f == 1) {
        if (a[i] < a[i - 1]) {
          v.push_back(a[i - 1]);
          f = 0;
        }
        if (i == n - 1) v.push_back(a[i]);
      } else {
        if (a[i] > a[i - 1]) {
          v.push_back(a[i - 1]);
          f = 1;
        }
        if (i == n - 1) v.push_back(a[i]);
      }
    }
    long long sum = 0;
    for (int i = 1; i < v.size(); i++) {
      sum += abs(v[i] - v[i - 1]);
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}
