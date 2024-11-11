#include <bits/stdc++.h>
using namespace std;
inline void read(void) {}
long long int n, a, b;
long long int data[100003];
vector<pair<long long int, long long int> > v;
inline void solve(void) {
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) scanf("%lld", &data[i]);
  for (int i = 0; i < n; i++) {
    printf("%lld ", ((data[i] * a) % b) / a);
  }
}
int main() {
  solve();
  return 0;
}
