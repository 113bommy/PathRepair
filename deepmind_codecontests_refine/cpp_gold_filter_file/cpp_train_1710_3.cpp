#include <bits/stdc++.h>
using namespace std;
const long long N = 1e7 + 5;
bool seive[N];
long long a[N];
long long process[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long m;
  cin >> m;
  for (long long i = 1; i <= n; i++) process[a[i]]++;
  for (long long i = 0; i < N; i++) seive[i] = 1;
  for (long long i = 2; i < N; i++) {
    if (seive[i]) {
      for (long long j = 2; i * j < N; j++) {
        process[i] += process[i * j];
        seive[i * j] = 0;
      }
    }
  }
  for (long long i = 0; i < N; i++) {
    if (!seive[i]) process[i] = 0;
    process[i] += process[i - 1];
  }
  for (long long i = 0; i < m; i++) {
    long long p, q;
    cin >> p >> q;
    cout << process[min(N - 1, q)] - process[min(N - 1, p - 1)] << "\n";
  }
  return 0;
}
