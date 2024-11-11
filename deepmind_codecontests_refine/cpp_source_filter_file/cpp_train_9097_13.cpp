#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000")
long long n;
long long a[100];
int main() {
  a[0] = 1;
  for (long long i = 1; i <= 39; i++) {
    a[i] = a[i - 1] * 3;
  }
  cin >> n;
  for (int i = 1; i <= 29; i++) {
    if (n % a[i]) {
      cout << n / a[i] + 1 << endl;
      return 0;
    } else
      continue;
  }
  cout << 1 << endl;
}
