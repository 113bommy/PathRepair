#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long cnt[1000000 + 10][30];
int main() {
  ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  string x, y;
  cin >> x >> y;
  if (x.size() < y.size()) {
    swap(x, y);
    swap(n, m);
  }
  int g = gcd(x.size(), y.size());
  for (int i = 0; i < g; i++) {
    for (int j = i; j < x.size(); j += g) {
      int cur = (int)(x[j] - 'a');
      cnt[i][cur]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < y.size(); i++) {
    int cur = (int)(y[i] - 'a');
    ans += (x.size() / g) - cnt[i % g][cur];
  }
  long long t = x.size();
  cout << (m / (t / (long long)g)) * ans << endl;
  return 0;
}
