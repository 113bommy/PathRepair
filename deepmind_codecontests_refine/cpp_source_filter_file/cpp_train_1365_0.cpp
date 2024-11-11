#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p;
  cin >> n >> p;
  long long int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  long long int s = a[p - 1] + b[0];
  long long int j = n - 1;
  long long int ans = 0;
  for (int i = 1; i < n; i++) {
    if (i == p - 1) i++;
    if (i < n && a[i] + b[j] <= s) {
      ans++;
      j--;
    }
  }
  cout << n - ans << endl;
  return 0;
}
