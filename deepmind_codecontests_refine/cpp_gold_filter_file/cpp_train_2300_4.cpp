#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  return b ? gcd(b, a % b) : a;
}
long long sqr(long long a) { return a * a; }
struct point {
  long long x, y;
};
struct straight {
  long long a, b, c;
};
long long n, m;
vector<pair<long long, long long> > a;
long long k = 0;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (m > n * (n - 1) / 2 || m < n - 1) return cout << "Impossible" << endl, 0;
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    for (long long j = i; j <= n; j++) {
      if (i + j != 2 && gcd(i, j) == 1) a.push_back(make_pair(i, j));
      if (a.size() == m) break;
    }
  if (a.size() != m) return cout << "Impossible" << endl, 0;
  cout << "Possible" << endl;
  for (long long i = 0; i < a.size(); i++)
    cout << a[i].first << " " << a[i].second << endl;
  return 0;
}
