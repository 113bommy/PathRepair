#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b) {
  long long p = 1;
  while (b) {
    if (b % 2) {
      p = p * a;
    }
    b >>= 1;
    a = a * a;
  }
  return p;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v;
  long long v1, v2;
  for (int i = 0; i < n; ++i) {
    cin >> v1 >> v2;
    v.push_back(make_pair(v1, v2));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; ++i) {
    if (v[i].second >= v[i + 1].second) {
      cout << "Happy Alex";
      return 0;
    }
  }
  cout << "Happy Dima";
}
