#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n);
  set<long long> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  int re = -1, res = -1;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < n; j++) {
      long long kk = a[j] + (1LL << i);
      long long pp = a[j] - (1LL << i);
      if (s.find(kk) != s.end() && s.find(pp) != s.end()) {
        cout << 3 << endl;
        cout << kk << " " << pp << " " << a[j] << endl;
        return 0;
      }
      if (s.find(kk) != s.end()) {
        re = kk;
        res = a[j];
      }
    }
  }
  if (re != -1 && res != -1) {
    cout << 2 << endl;
    cout << re << " " << res << endl;
  } else {
    cout << 1 << endl;
    cout << a[0] << endl;
  }
}
