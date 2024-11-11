#include <bits/stdc++.h>
const long long INF = 1e9;
const long long MOD = 1e9 + 7;
const long long zero = 0;
const long long N = 1e5 + 5;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, l = 3, arr[2] = {1, 2};
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == l) {
      return cout << "NO", 0;
    }
    if (arr[0] == a[i])
      swap(l, arr[1]);
    else
      swap(l, arr[0]);
  }
  cout << "YES";
}
