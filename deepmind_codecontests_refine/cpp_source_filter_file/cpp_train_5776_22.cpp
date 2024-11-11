#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 110000;
int arr[N];
long long arr1[N];
long long arr2[N];
int m, r, t;
int main() {
  string s;
  cin >> s;
  n = s.length();
  for (int i = 1; i <= n; i++)
    arr[i] = s[i - 1] == 'A' || s[i - 1] == 'E' || s[i - 1] == 'I' ||
             s[i - 1] == 'O' || s[i - 1] == 'U' || s[i - 1] == 'Y';
  for (int i = 1; i <= n; i++) {
    arr1[i] = arr1[i - 1] + arr[i];
    arr2[i] = arr2[i - 1] + arr1[i];
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (double)(arr2[n] - arr2[i - 1] - arr2[n - i]) / (i + 0.0);
  }
  cout << fixed << setprecision(7) << ans << endl;
  return 0;
}
