#include <bits/stdc++.h>
using namespace std;
const int32_t mod = 1e9 + 7;
const long long inf = 1e18;
const long long N = 1e5 + 5;
void testCases() {
  long long n, x;
  cin >> n >> x;
  vector<long long> V[n + 4];
  vector<long long> s(n + 4, 0);
  for (long long i = 0; i < n - 1; i++) {
    long long a, b;
    cin >> a >> b;
    V[a].push_back(b);
    V[b].push_back(a);
    s[a]++;
    s[b]++;
  }
  if (s[x] <= 1)
    cout << "Ayush\n";
  else {
    if (n % 2 == 1)
      cout << "Ashish\n";
    else
      cout << "Ayush\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tcs = 1;
  cin >> tcs;
  while (tcs--) {
    testCases();
  }
}
