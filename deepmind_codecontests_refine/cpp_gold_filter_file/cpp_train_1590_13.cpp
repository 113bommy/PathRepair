#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  long long int min = LLONG_MAX;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int c = 0;
  sort(a, a + n);
  int f = 0;
  int i = 1;
  while (pow(i, n - 1) <= pow(10, 10)) i++;
  i--;
  int l = 1;
  while (l <= i) {
    long long int x = 0;
    for (int k = 0; k < n; k++) {
      x += abs((long long)a[k] - (long long)pow(l, k));
    }
    if (x < min) min = x;
    l++;
  }
  cout << min << endl;
}
