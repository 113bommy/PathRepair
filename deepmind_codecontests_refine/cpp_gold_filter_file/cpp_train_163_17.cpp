#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<long long int> ar, br;
bool predicate(long long int x, long long int p) {
  long long int n = ar.size(), k = br.size();
  long long int firstptr = 0, secptr = 0;
  while ((firstptr < n) and (secptr < k)) {
    long long int tim =
        llabs(ar[firstptr] - br[secptr]) + llabs(br[secptr] - p);
    if (tim <= x) {
      firstptr++;
      secptr++;
    } else {
      secptr++;
    }
  }
  if (firstptr < n) {
    return false;
  } else
    return true;
}
void Compute(long long int n, long long int k, long long int p) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ar.resize(n);
  br.resize(k);
  for (long long int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  for (long long int i = 0; i < k; i++) {
    cin >> br[i];
  }
  sort(ar.begin(), ar.end());
  sort(br.begin(), br.end());
  long long int lo = -1, hi = 1e14 + 1;
  while ((lo + 1) < hi) {
    long long int mid = (lo + hi) / 2;
    if (predicate(mid, p))
      hi = mid;
    else
      lo = mid;
  }
  cout << lo + 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, k, p;
  cin >> n >> k >> p;
  Compute(n, k, p);
}
