#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(const T& t) {
  ostringstream os;
  os << t;
  return os.str();
}
bool sieve[2000000 + 1];
int DP[2000002];
void sieve_erastothenes() {
  register unsigned int p;
  sieve[0] = sieve[1] = true;
  for (p = 2;; ++p) {
    unsigned long long p2 = ((unsigned long long)p) * ((unsigned long long)p);
    if (p2 > 2000000) break;
    if ((sieve[(p)])) continue;
    for (unsigned long long k = p2; k <= 2000000; k += p) sieve[k] = true;
  }
}
int a, b, k;
int check(int l) {
  for (int x = a; x <= b - l + 1; ++x)
    if (DP[x + l - 1] - DP[x - 1] < k) return false;
  return true;
}
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve_erastothenes();
  DP[1] = 0;
  for (int i = 2; i <= 2000000; ++i) {
    DP[i] = DP[i - 1];
    if ((sieve[(i)])) continue;
    DP[i]++;
  }
  cin >> a >> b >> k;
  int lo = 1;
  int hi = b - a + 1;
  while (lo < hi) {
    int l = lo + (hi - lo) / 2;
    if (check(l))
      hi = l;
    else
      lo = l + 1;
  }
  if (!check(lo)) {
    cout << -1 << endl;
    return 0;
  }
  cout << lo << endl;
  return 0;
}
