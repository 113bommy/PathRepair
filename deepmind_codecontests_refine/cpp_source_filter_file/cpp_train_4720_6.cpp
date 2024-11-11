#include <bits/stdc++.h>
using namespace std;
const int N = 10000009;
int a[N];
int main() {
  long long n, x;
  cin >> x >> n;
  for (int i = 1; i < x + n; i++) a[i] = i;
  for (int i = 2; i * i <= x + n; i++) {
    int k = 0;
    for (int j = i * i; j <= x + n; j += i * i) {
      k++;
      a[j] = k;
    }
  }
  int sum = 0;
  for (int i = x; i < x + n; i++) sum += a[i];
  cout << sum << endl;
}
