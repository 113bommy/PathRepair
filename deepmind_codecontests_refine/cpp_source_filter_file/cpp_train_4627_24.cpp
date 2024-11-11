#include <bits/stdc++.h>
using namespace std;
int n, b;
int *a;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> b;
  a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      long long int dollar = b / a[i];
      long long int f = b % a[i] + dollar * a[j];
      ans = max(ans, f);
    }
  }
  cout << ans;
}
