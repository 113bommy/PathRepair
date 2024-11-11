#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long p = 0;
  for (int i = 0; i < n; i++) {
    p += a[i] * a[n - i - 1];
    p %= 10007;
  }
  cout << p;
}
