#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a[n];
  long long e = 0;
  long long o = 0;
  vector<long long> v1;
  vector<long long> v2;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      e++;
      v1.push_back(a[i]);
    } else {
      o++;
      v2.push_back(a[i]);
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  long long m = (e - o);
  if (m < 0) {
    m = -m;
  }
  if (m <= 1) {
    cout << "0" << endl;
  } else {
    long long ans = 0;
    if (o == 0) {
      for (long long i = 0; i < v1.size() - 1; i++) {
        ans += v1[i];
      }
    } else if (e == 0) {
      for (long long i = 0; i < v2.size() - 1; i++) {
        ans += v2[i];
      }
    } else if (e < o) {
      for (long long i = 0; i <= e; i++) {
        v2.pop_back();
      }
      for (long long i = 0; i < v2.size(); i++) {
        ans += v2[i];
      }
    } else {
      for (long long i = 0; i <= o; i++) {
        v1.pop_back();
      }
      for (long long i = 0; i < v1.size(); i++) {
        ans += v1[i];
      }
    }
    cout << ans << endl;
  }
}
