#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[40] = {0};
  for (int i = 0; i < 40; i++) {
    long long x = 1;
    for (int j = 0; j < 10; j++) x *= i;
    a[i] = x;
  }
  long long k, n;
  cin >> k;
  int i = 0, e = 0;
  while (k > a[i]) i++;
  if (k < a[i]) {
    i--;
    long long val = a[i];
    for (int j = 0; j < 10; j++) {
      e++;
      val /= i;
      val *= (i + 1);
      if (val >= k) break;
    }
  }
  string s = "codeforces";
  for (int j = 0; j < 10; j++) {
    for (int l = 0; l < i; l++) cout << s[j];
    if (e) {
      cout << s[j];
      e--;
    }
  }
  cout << endl;
  return 0;
}
