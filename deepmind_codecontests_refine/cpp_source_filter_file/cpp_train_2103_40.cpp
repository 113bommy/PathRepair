#include <bits/stdc++.h>
using namespace std;
bool isPrime(int N) {
  for (int i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first > b.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k, i = 1, j = 1, ind, count, l, ans = 1, a, b, c, d;
    cin >> a >> b >> c >> d >> k;
    if (a % c == 0) {
      i = a / c;
    } else {
      i = a / c + 1;
    }
    if (a % c == 0) {
      j = b / d;
    } else {
      j = b / d + 1;
    }
    if (i + j <= k) {
      cout << i << " " << k - i;
    } else
      cout << "-1";
    cout << "\n";
  }
  return 0;
}
