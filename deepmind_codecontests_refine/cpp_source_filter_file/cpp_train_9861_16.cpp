#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  long long n, k;
  cin >> n >> k;
  array<long long, 3> a[n];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i][0];
    a[i][2] = i;
  }
  for (long long i = 0; i < n; ++i) cin >> a[i][1];
  sort(a, a + n);
  set<long long> second;
  long long sum = 0;
  array<long long, 2> ar[n];
  for (long long i = 0; i < n; ++i) {
    ar[i][0] = a[i][2];
    ar[i][1] = a[i][1];
  }
  if (k != 0) {
    for (long long i = 0; i < n; ++i) {
      ar[i][1] += sum;
      if (second.size() >= k) {
        if (*second.begin() < a[i][1]) {
          sum -= *second.begin();
          second.erase(second.begin());
          second.insert(a[i][1]);
          sum += a[i][1];
        } else {
        }
      } else {
        second.insert(a[i][1]);
        sum += a[i][1];
      }
    }
  }
  sort(ar, ar + n);
  for (long long i = 0; i < n; ++i) {
    cout << ar[i][1] << " ";
  }
  cout << endl;
  return 0;
}
