#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9, M = 1e3 + 9;
bool ask(long long int k) {
  cout << k << endl;
  fflush(stdout);
  long long int t;
  cin >> t;
  if (t == 0) exit(0);
  if (t == 1) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long int n, m;
  cin >> m >> n;
  bool seq[n];
  for (long long int i = 0; i <= n - 1; i++) {
    seq[i] = ask(1);
  }
  long long int l = 1, r = m, itr = 0;
  while (l <= r) {
    long long int mid = l + (r - l) / 2;
    bool choto = ask(mid);
    if (!seq[itr]) choto = !choto;
    if (choto)
      l = mid + 1;
    else
      r = mid - 1;
    itr += 1;
    itr %= m;
  }
  return 0;
}
