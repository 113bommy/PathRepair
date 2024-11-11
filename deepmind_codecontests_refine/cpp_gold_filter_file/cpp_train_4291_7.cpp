#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long flag = 0, flag2 = 0;
  map<long long, long long> mm;
  set<long long> s;
  vector<long long> v;
  set<long long>::iterator itr;
  long long n;
  cin >> n;
  string a;
  cin >> a;
  long long cnt = 0, cnt2 = 0;
  for (long long i = 1; i < n - 1; i++) {
    if (a[i] != a[0]) {
      a[i] = a[0];
      if (a[i + 1] == 'W')
        a[i + 1] = 'B';
      else
        a[i + 1] = 'W';
      v.push_back(i + 1);
      cnt++;
    }
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == a[0]) cnt2++;
  }
  if (cnt2 == n) {
    cout << cnt << endl;
    for (std::vector<long long>::iterator i = v.begin(); i != v.end(); ++i) {
      cout << *i << " ";
    }
    cout << endl;
  } else if (n % 2 != 0) {
    for (long long i = 0; i < n - 1; i = i + 2) {
      cnt++;
      v.push_back(i + 1);
    }
    cout << cnt << endl;
    for (std::vector<long long>::iterator i = v.begin(); i != v.end(); ++i) {
      cout << *i << " ";
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }
}
