#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n, i;
  cin >> d >> n;
  long long int a[100000];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  for (i = 0; i < n - 1; i++) {
    sum += d - a[i];
  }
  cout << sum << endl;
}
