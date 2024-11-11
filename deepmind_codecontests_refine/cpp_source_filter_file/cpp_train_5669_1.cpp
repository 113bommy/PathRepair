#include <bits/stdc++.h>
using namespace std;
void enter(vector<long long int> &ar) {
  long long int n = ar.size();
  for (long long int i = 0; i < n; i++) {
    cin >> ar[i];
  }
}
void show(vector<long long int> &a) {
  long long int n = a.size();
  for (long long int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
void SieveOfErat1sthenes(int n, vector<long long int> &pri) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      pri.push_back(p);
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
}
long long int mo(long long int a) { return a % (long long int)(1e9 + 7); }
vector<long long int> a;
long long int func(long long int l, long long int r) {
  if (l > r) return 0;
  long long int pos = l, mi = a[l];
  for (long long int i = l; i <= r; i++) {
    if (mi > a[i]) {
      l = i;
      mi = a[i];
    }
  }
  for (long long int i = l; i <= r; i++) a[i] -= mi;
  return min(r - l + 1, func(l, pos - 1) + func(pos + 1, r) + mi);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  a.resize(n);
  enter(a);
  long long int ans = func(0, n - 1);
  cout << ans << "\n";
  return 0;
}
