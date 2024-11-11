#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, a[100005] = {}, s, sum = 0;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (i = 0; i < n - 1; i++) sum += a[i];
  if (sum > s)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
