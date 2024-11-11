#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long minNumNod = k * (1 + k) / 2;
  if (minNumNod > n || k > 1e5) {
    cout << -1 << endl;
    return 0;
  }
  long long nod = 1;
  for (long long i = 2; i * i <= n; i++) {
    if (minNumNod * i > n) break;
    if (n % i == 0) {
      if (n / i * minNumNod <= n) {
        nod = n / i;
        break;
      } else
        nod = i;
    }
  }
  long long numNod = n / nod;
  long long ost = numNod - minNumNod;
  for (long long i = 1; i < k; i++) {
    cout << i * nod << " ";
  }
  cout << k * nod + ost * nod << endl;
  return 0;
}
