#include <bits/stdc++.h>
using namespace std;
bool ask(long long x) {
  cout << "? " << x << "\n";
  cout.flush();
  char c;
  cin >> c;
  return (c == 'Y');
}
void R() {
  cout << "R"
       << "\n";
  cout.flush();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  vector<long long> dead(n);
  for (long long i = 0; i < n; i++) {
    if (ask(i + 1)) {
      dead[i] = 1;
    }
  }
  R();
  long long tam = max(1LL, k / 2);
  vector<long long> g[n / tam];
  for (long long i = 0; i < n; i++) {
    g[i / tam].push_back(i);
  }
  for (long long i = 0; i < n / tam; i++) {
    for (long long j = i + 1; j < n / tam; j++) {
      for (long long x : g[i]) {
        if (ask(x + 1)) {
          dead[x] = 1;
        }
      }
      for (long long y : g[j]) {
        if (ask(y + 1)) {
          dead[y] = 1;
        }
      }
      R();
    }
  }
  cout << "! " << n - accumulate(dead.begin(), dead.end(), 0) << "\n";
  cout.flush();
}
