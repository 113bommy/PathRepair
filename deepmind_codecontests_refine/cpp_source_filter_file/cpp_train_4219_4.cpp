#include <bits/stdc++.h>
using namespace std;
char U[26], L[26];
int main() {
  long long n, m, sum = 0, cnt = 0;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    if (sum == m) break;
    sum += a[i];
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}
