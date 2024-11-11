#include <bits/stdc++.h>
using namespace std;
long long a[6000000];
int main() {
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  cout << a[k];
  return 0;
}
