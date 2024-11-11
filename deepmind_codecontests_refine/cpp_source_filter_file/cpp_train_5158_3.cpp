#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
long long exp(long long a, long long b) {
  long long ans = 1;
  while (b != 0) {
    if (b % 2) ans = ans * a;
    a = a * a;
    b /= 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b;
  cin >> a >> b;
  long long ans = 0;
  for (long long i = (long long)1; i < (long long)a + 1; i++) {
    long long val = i / 5 + 1;
    long long a = val * 5 - i;
    long long x = b - a;
    if (b < 0) continue;
    long long k = x / 5;
    k++;
    ans += k;
  }
  cout << ans << endl;
  return 0;
}
