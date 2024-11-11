#include <bits/stdc++.h>
long long i, j;
long long max1 = INT_MIN, min1 = INT_MAX;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  string s;
  cin >> n >> s;
  int a[10];
  for (i = 1; i < 10; i++) {
    cin >> a[i];
  }
  for (i = 0; s[i]; i++) {
    int m = s[i] - 48;
    if (a[m] > m) {
      while (a[m] >= m) {
        s[i] = a[m] + 48;
        i++;
        m = s[i] - 48;
      }
      break;
    }
  }
  cout << s;
  return 0;
}
