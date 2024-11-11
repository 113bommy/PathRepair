#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  long long arr[] = {(k * l) / (nl * n), d * c / n, p / (np * n)};
  long long g = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + g);
  cout << arr[0];
}
