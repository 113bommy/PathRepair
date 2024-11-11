#include <bits/stdc++.h>
using namespace std;
long long int n;
int a[2000007];
long long int tmp, re, sum, dem1, dem2;
void _love() { cin >> n; }
void _nang_am() {
  for (long long int i = 1; i <= 100000; i++) {
    tmp = i;
    while (tmp % 2 == 0) {
      dem1++;
      tmp /= 2;
    }
    while (tmp % 5 == 0) {
      dem2++;
      tmp /= 5;
    }
    dem2 = min(dem2, dem1);
    if (dem2 == n) {
      cout << 5 << "\n";
      for (long long int j = 1; j <= 5; j++) {
        cout << i + j - 1 << " ";
      }
      return;
    }
  }
  cout << "0"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  _love();
  _nang_am();
  return 0;
}
