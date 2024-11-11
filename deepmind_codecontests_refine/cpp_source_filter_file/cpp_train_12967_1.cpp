#include <bits/stdc++.h>
using namespace std;
int a[4000001];
int b[4000001];
int rakha[4000001];
map<int, int> mp;
int main() {
  int n, t, i, j, n1, k, ans, f = 0, s = 0, c = 0, p = 1, c1 = 0, p1 = 0,
                              p2 = 0, res = 0, c2, s1, s2, pp = 1000000, m;
  string str;
  cin >> n >> k;
  m = n / k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (i = 0; i < n; i++) {
    if (a[i] > k) {
      f = 0;
      for (j = 1; j <= k; j++) {
        if (mp[j] < m) {
          f = 1;
        }
      }
      if (f == 1) {
        s1 = pp;
        p1++;
        f = 0;
        for (j = 1; j <= k; j++) {
          if (mp[j] < m) {
            s2 = j;
          }
        }
        mp[s2]++;
        a[i] = s2;
      }
    } else {
      s2 = mp[a[i]];
      f = 0;
      if (s > m) {
        for (j = 1; j <= k; j++) {
          if (mp[j] < m) {
            f = 1;
            s2 = j;
          }
        }
        if (f == 1) {
          p1++;
          mp[a[i]]--;
          mp[s2]++;
          a[i] = s2;
        }
      }
    }
  }
  s2 = pp;
  s1 = 1;
  for (i = 1; i <= k; i++) {
    s2 = min(s2, mp[i]);
  }
  cout << s2 << " " << p1 << endl;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
