#include <bits/stdc++.h>
long long int power(long long int x, long long int b, long long int mod1) {
  long long int p = 1;
  while (b > 0) {
    if (b & 1) {
      p = p * x;
      p %= mod1;
    }
    b >>= 1;
    x *= x;
    x %= mod1;
  }
  return p % mod1;
}
using namespace std;
struct lex_compare {
  bool operator()(const pair<long long int, long long int> p1,
                  const pair<long long int, long long int> p2) {
    return p1.first > p2.first;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int n, x, y;
  cin >> n >> x >> y;
  long long int arr[n];
  double left = n;
  long long int sum = 0;
  if (n > y) {
    cout << -1 << "\n";
    return 0;
  }
  arr[0] = ceil(sqrt(max(0.00, double(x - n + 1))));
  for (long long int i = 1; i < n; i++) arr[i] = 1;
  if (n - 1 + arr[0] > y || (arr[0] * arr[0] + n - 1) < x) {
    cout << -1 << "\n";
    return 0;
  }
  for (long long int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return 0;
}
