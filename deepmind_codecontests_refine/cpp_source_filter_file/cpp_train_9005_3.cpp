#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long from, to, w;
  edge(long long from, long long to, long long w) : from(from), to(to), w(w) {}
  bool operator<(const edge& e) const { return ((w > e.w)); }
};
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long fx(long long n) {
  return ((n % 1000000007) + 1000000007) % 1000000007;
}
void O_o() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  O_o();
  int n, m, a, b, x;
  cin >> n >> m;
  int arr[n + 1], sum[n + 5];
  sum[0] = arr[0] = 0;
  for (int i = 1; i <= int(n); i++) {
    cin >> arr[i];
    sum[i] = (arr[i] == arr[i - 1]) ? sum[i - 1] : i;
  }
  while (m--) {
    cin >> a >> b >> x;
    if (arr[sum[b]] != x)
      cout << b;
    else if (sum[b] > a)
      cout << sum[b];
    else
      cout << -1;
    cout << endl;
  }
  return 0;
}
