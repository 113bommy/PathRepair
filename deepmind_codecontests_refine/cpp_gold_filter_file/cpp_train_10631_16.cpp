#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a[100005], sum = 0;
  cin >> n;
  long long i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sum = 0;
  cout << n + 1 << "\n";
  for (i = n - 1; i >= 0; i--) {
    a[i] += sum;
    cout << 1 << " " << i + 1 << " " << i + n - a[i] % n << "\n";
    sum += i + n - a[i] % n;
  }
  cout << 2 << " " << n << " " << n;
}
