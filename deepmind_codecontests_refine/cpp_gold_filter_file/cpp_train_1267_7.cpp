#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long int);
long long int gcd(long long int, long long int);
set<long long int> divs(long long int);
void swap(long long int& x, long long int& y) {
  long long int tmp = x;
  x = y;
  y = tmp;
}
const long long int N = 1000;
long long int cols[N], rows[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n, x, y;
  cin >> n >> x >> y;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  long long int r = 0;
  set<long long int> pfx, sfx;
  for (long long int i = 0; i < y; i++) sfx.insert(arr[min(i, n - 1)]);
  for (long long int i = 0; i < n; i++) {
    if (i - x > 0) {
      pfx.insert(arr[i - x]);
      pfx.erase(arr[i - x - 1]);
    } else {
      if (i) pfx.insert(arr[i - 1]);
    }
    if (i + y < n) {
      sfx.insert(arr[i + y]);
      sfx.erase(arr[i]);
    } else {
      if (sfx.size()) sfx.erase(arr[i]);
    }
    if (!pfx.size() || arr[i] <= *pfx.begin()) {
      if (!sfx.size() || arr[i] <= *sfx.begin()) {
        r = i + 1;
        break;
      }
    }
  }
  cout << r;
}
bool is_prime(long long int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  for (long long int i = 2; i <= (long long int)sqrt(n); i++) {
    if ((n % i) == 0) return 0;
  }
  return 1;
}
long long int gcd(long long int x, long long int y) {
  return y == 0 ? x : gcd(y, x % y);
}
set<long long int> divs(long long int n) {
  set<long long int> st;
  for (long long int i = 1; i <= (long long int)sqrt(n); i++) {
    if (n % i == 0) {
      st.insert(i);
      st.insert(n / i);
    }
  }
  return st;
}
