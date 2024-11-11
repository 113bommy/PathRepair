#include <bits/stdc++.h>
using namespace std;
unsigned long long int expo_fast(long long int a, long long int b) {
  a = a;
  long long int result = 1;
  while (b) {
    if (b & 1) result = (result * a);
    b >>= 1;
    a = (a * a);
  }
  return (result);
}
void take_in(vector<long long int> *arr) {
  for (int i = 0; i < arr->size(); i++) cin >> (*(arr))[i];
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
unsigned long long int power(long long int x, unsigned long long int y,
                             long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<long long int, long long int> > a(n);
  for (int i = 0; i < n; i++) {
    long long int x, w;
    cin >> x >> w;
    a[i] = {x - w + 1, x + w - 1};
  }
  auto cmp = [](const pair<long long int, long long int> &x,
                const pair<long long int, long long int> &y) -> bool {
    if (x.second < y.second) return true;
    return false;
  };
  sort(a.begin(), a.end(), cmp);
  long long int ans = 1;
  auto prev = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i].first > prev.second) {
      ans++;
      prev = a[i];
    }
  }
  cout << ans;
}
