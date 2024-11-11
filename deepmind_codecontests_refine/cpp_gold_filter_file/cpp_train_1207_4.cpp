#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1000000000000030200;
const int A = 1234567;
long long arr[5000];
int main() {
  long long mx, n;
  cin >> n >> mx;
  for (int i = 0; i < (int)(n); ++i) cin >> arr[i];
  sort(arr, arr + n);
  long long out = 0;
  for (int i = 0; i < n; i++) {
    while (arr[i] > mx * 2) {
      mx *= 2;
      out++;
    }
    if (arr[i] > mx) mx = arr[i];
  }
  cout << out;
  return 0;
}
