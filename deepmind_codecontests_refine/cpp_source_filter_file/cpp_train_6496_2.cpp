#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  long long n, m;
  cin >> n >> m;
  long long a[m];
  a[0] = 0;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long y = 0;
  for (long long i = 0; i < m; i++) {
    if (a[i] > a[i - 1]) {
      y = y + (a[i] - a[i - 1]);
    } else if (a[i] < a[i - 1]) {
      y = y + (n - a[i - 1]) + (a[i]);
    } else if (a[i] == a[i - 1]) {
      y = y + 0;
    }
  }
  cout << y << endl;
  return 0;
}
