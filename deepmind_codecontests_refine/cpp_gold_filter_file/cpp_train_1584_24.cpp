#include <bits/stdc++.h>
using namespace std;
int const N = 5e5 + 5;
int const mod = 1e9 + 7;
long double min(long double x, long double y) {
  if (x < y)
    return x;
  else
    return y;
}
long double max(long double x, long double y) {
  if (x > y)
    return x;
  else
    return y;
}
long long gcd(long long x, long long y) {
  if (x == 0)
    return y;
  else
    return gcd(y % x, x);
}
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first < b.first)
    return true;
  else if (a.first == b.first)
    return (a.second > b.second);
  else
    return false;
}
bool sortbysec(const int &a, const int &b) {
  if (a > b)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  while (tt--) {
    long long n;
    cin >> n;
    cout << 9 * n << " " << 8 * n << endl;
  }
}
