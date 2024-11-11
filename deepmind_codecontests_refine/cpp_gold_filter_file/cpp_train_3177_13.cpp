#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[3], b[3];
  cin >> a[0] >> a[1] >> a[2];
  cin >> b[0] >> b[1] >> b[2];
  long long e = 0, jr = 0;
  for (long long i = 0; i < 3; i++) {
    if (a[i] >= b[i]) {
      e += (a[i] - b[i]) / 2;
    } else
      jr += b[i] - a[i];
  }
  if (e >= jr)
    cout << "YES";
  else
    cout << "NO";
}
