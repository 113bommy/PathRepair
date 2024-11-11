#include <bits/stdc++.h>
using namespace std;
int main() {
  string second[4];
  for (long long i = 0; i < 4; i++) cin >> second[i];
  long long a[4] = {0};
  a[0] = second[0].length() - 2;
  a[1] = second[1].length() - 2;
  a[2] = second[2].length() - 2;
  a[3] = second[3].length() - 2;
  long long cnt = 0;
  long long ans1 = -1;
  map<long long, char> m;
  m[0] = 'A';
  m[1] = 'B';
  m[2] = 'C';
  m[3] = 'D';
  for (long long i = 0; i < 4; i++) {
    cnt = 0;
    for (long long j = 0; j < 4; j++) {
      if (i != j) {
        if (2 * a[i] <= a[j]) {
          cnt++;
        }
      }
    }
    if (cnt == 3) ans1 = i;
  }
  long long ans2 = -1;
  for (long long i = 0; i < 4; i++) {
    cnt = 0;
    for (long long j = 0; j < 4; j++) {
      if (i != j) {
        if (a[i] >= 2 * a[j]) {
          cnt++;
        }
      }
    }
    if (cnt == 3) ans2 = i;
  }
  if ((ans1 == -1 && ans2 == -1) || (ans1 >= 0 && ans2 >= 0))
    cout << "C"
         << "\n";
  else {
    if (ans1 >= 0)
      cout << m[ans1] << "\n";
    else
      cout << m[ans2] << "\n";
  }
  return 0;
}
