#include <bits/stdc++.h>
using namespace std;
long long ask(vector<long long>& a) {
  cout << "? " << (long long)(a.size()) << " ";
  for (auto& u : a) cout << u << " ";
  cout << endl;
  long long ans;
  cin >> ans;
  return ans;
}
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1, -1);
    for (long long i = 0; i < k; i++) {
      long long x;
      cin >> x;
      while (x--) {
        long long y;
        cin >> y;
        a[y] = i + 1;
      }
    }
    vector<long long> b;
    for (long long i = 1; i <= n; i++) b.push_back(i);
    long long mx = ask(b);
    long long l = 1;
    long long h = n;
    long long pos = -1;
    while (l < h) {
      long long m = (l + h) >> 1;
      vector<long long> c;
      for (long long i = l; i <= m; i++) c.push_back(i);
      long long cur_mx = ask(c);
      if (cur_mx == mx) {
        h = m;
        pos = l;
      } else {
        l = m + 1;
        pos = h;
      }
    }
    if (a[pos] != -1) {
      long long not_grp = a[pos];
      vector<long long> c;
      for (long long i = 1; i <= n; i++)
        if (a[i] != not_grp) c.push_back(i);
      long long sec_mx = ask(c);
      cout << "! ";
      for (long long i = 1; i <= k; i++) {
        if (not_grp == i)
          cout << sec_mx << " ";
        else
          cout << mx << " ";
      }
      cout << endl;
    } else {
      cout << "! ";
      for (long long i = 1; i <= k; i++) cout << mx << ' ';
      cout << endl;
    }
    string s;
    cin >> s;
    if (s[0] != 'C') return 0;
  }
}
