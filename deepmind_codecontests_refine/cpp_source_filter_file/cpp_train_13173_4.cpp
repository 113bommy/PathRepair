#include <bits/stdc++.h>
long long myFnc(long long a, long long b) { return a > b; }
using namespace std;
int main() {
  long long n, d, i, j, count = 0, p = 0, b[100];
  string s;
  cin >> n >> d;
  j = 0;
  while (d--) {
    cin >> s;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') p = 1;
    }
    if (p == 0) {
      b[j] = count;
      j++;
      count = 0;
      p = 0;
    } else {
      count++;
      p = 0;
    }
  }
  b[j] = count;
  sort(b, b + j, myFnc);
  for (i = 0; i < 1; i++) cout << b[i] << endl;
}
