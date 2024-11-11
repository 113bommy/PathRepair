#include <bits/stdc++.h>
using namespace std;
long long a[100000];
long long b[100000];
int main(int argc, char *argv[]) {
  long n, tong1 = 0, tong2 = 0;
  cin >> n;
  for (long i = 0; i < n; i++) {
    cin >> a[i];
    tong1 += a[i];
  }
  for (long i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(b, b + n);
  tong2 = (b[n - 1] + b[n - 2]);
  if (tong1 <= tong2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
