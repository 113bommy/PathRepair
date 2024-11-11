#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int p,
                 long long int m = 1000000007) {
  if (p == 1) return a;
  long long int t = pw(a, p / 2);
  t = (m + (t * t) % m) % m;
  if (p % 2 != 0) t *= a;
  return (t + m) % m;
}
void solve() {
  long long int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  long long int tot = 0;
  for (long long int i = 0; i < (n / 2); i++) {
    map<char, long long int> mp;
    mp[a[i]]++;
    mp[a[n - i - 1]]++;
    mp[b[i]]++;
    mp[b[n - i - 1]]++;
    vector<long long int> ind;
    for (auto i : mp) ind.push_back(i.second);
    sort((ind).begin(), (ind).end());
    if (ind.size() == 4) {
      tot += 4;
    } else if (ind.size() == 3) {
      if (a[i] == a[n - i - 1])
        tot += 2;
      else
        tot += 1;
    } else if (ind.size() == 2) {
      if (ind[0] != ind.back()) tot++;
    }
  }
  if (n % 2 == 1) {
    if (a[n / 2] != b[n / 2]) tot++;
  }
  cout << tot << endl;
}
int main() {
  ios::sync_with_stdio(0);
  long long int t = 1;
  for (long long int i = 0; i < (t); i++) solve();
}
