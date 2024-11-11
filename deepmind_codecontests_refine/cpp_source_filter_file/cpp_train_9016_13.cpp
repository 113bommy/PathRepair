#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  map<int, int> mp;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] % m;
    s.insert(b[i]);
    mp[b[i]]++;
  }
  int maxx = 0;
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    int keep = *it;
    if (mp[keep] >= k) {
      cout << "YES" << endl;
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (b[i] == keep) {
          cout << a[i] << " ";
          cnt++;
        }
        if (cnt == k) return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
