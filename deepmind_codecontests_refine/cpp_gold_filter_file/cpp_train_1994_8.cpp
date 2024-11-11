#include <bits/stdc++.h>
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long MOD = 1e9 + 7;
int main() {
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> mp;
    long long val;
    long long mx = -1;
    vector<long long> vc;
    for (long long i = 0; i < n; ++i) {
      cin >> a[i];
      if (mp[a[i]] == 0) {
        mp[a[i]]++;
        vc.push_back(a[i]);
      }
    }
    if (vc.size() > 3) {
      cout << -1 << '\n';
      return 0;
    }
    map<long long, long long>::iterator it;
    it = mp.begin();
    if (vc.size() == 2) {
      long long fs = vc[0];
      long long sss = vc[1];
      if (abs(fs - sss) % 2 == 1)
        cout << abs(fs - sss);
      else
        cout << abs(fs - sss) / 2;
      return 0;
    }
    if (vc.size() == 1) {
      cout << 0 << '\n';
      return 0;
    } else {
      sort((vc).begin(), (vc).end());
      if (vc[1] - vc[0] == vc[2] - vc[1]) {
        cout << vc[1] - vc[0] << '\n';
      } else
        cout << -1 << '\n';
    }
  }
}
