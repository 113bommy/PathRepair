#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[200];
map<long long, long long> mp;
vector<pair<long long, long long> > b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  for (long long i = 1; i <= n; ++i) {
    mp[a[i]]++;
  }
  long long max1 = 1;
  for (auto p : mp) {
    long long ot = p.second / k;
    if (p.second % k != 0) {
      ot += 1;
    }
    max1 = max(max1, ot);
  }
  long long kol = k * max1 * (long long)mp.size();
  cout << kol - n << endl;
}
