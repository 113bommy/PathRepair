#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test = 1;
  cin >> test;
  while (test--) {
    long long n, m, k;
    cin >> n >> m >> k;
    long long t1 = n % m;
    long long t2 = m - t1;
    long long id = 0;
    while (k--) {
      for (long long i = 0; i < t1; i++) {
        cout << n / m + 1 << " ";
        for (long long j = 0; j < n / m + 1; j++) {
          cout << id % n + 1 << " ";
          id++;
        }
        cout << "\n";
      }
      for (long long i = 0; i < t2; i++) {
        cout << n / m << " ";
        for (long long j = 0; j < n / m; j++) {
          cout << id % n + 1 << " ";
          id++;
        }
        cout << "\n";
      }
      id += (n / m) * t2;
    }
    cout << "\n";
  }
  return 0;
}
