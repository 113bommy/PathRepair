#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long e;
    cin >> e;
    a.push_back(e);
  };
  long long c = 1;
  long long m = 0;
  for (long long i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) {
      c++;
    } else {
      m = max(m, c);
      c = 1;
    }
  }
  m = max(m, c);
  cout << m << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) solve();
  return 0;
}
