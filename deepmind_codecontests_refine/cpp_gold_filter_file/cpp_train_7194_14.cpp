#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, e, f, g, n, m, k, l, A[200005], r, maxx;
char ch;
map<long long, long long> mp, mp1;
map<long long, char> mp2;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> A[i];
  A[0] = 0;
  A[n + 1] = 1001;
  for (long long i = 0; i <= n; i++)
    if (A[i] + 1 == A[i + 1])
      k++;
    else {
      maxx = max(maxx, k);
      k = 0;
    }
  maxx = max(maxx, k);
  cout << max(maxx - 1, (long long)0);
}
