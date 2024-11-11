#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long t = 0;
  long long t1 = 0;
  for (long long i = 0; i < n; i++) {
    t += a[i];
    long long c = t / m;
    cout << c - t1 << " ";
    t1 += (c - t1);
  }
}
