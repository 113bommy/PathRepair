#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  long long a[t + 10];
  for (long long i = 0; i < t; i++) {
    cin >> a[i];
  }
  sort(a, a + t);
  long long l = 0, cnt = 0;
  for (long long i = 0; i < t; i++) {
    if (a[i] >= l) {
      l += a[i];
      cnt++;
    }
  }
  cout << cnt << endl;
}
