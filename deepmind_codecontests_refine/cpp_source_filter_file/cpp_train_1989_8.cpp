#include <bits/stdc++.h>
long long int MMM = 1000000007;
int pw(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % MMM)
    if (y & 1) z = 1ll * z * x % MMM;
  return z;
}
using namespace std;
bool sortbysecdesc(const pair<long long int, long long int> &a,
                   const pair<long long int, long long int> &b) {
  return a.first > b.first;
}
bool cmp(int x, int y) { return x > y; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, x, mx = 0, sum = 0;
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
    mx = max(mx, x);
  }
  cout << ((sum + m + n - 1) / n) << " " << mx + m << endl;
}
