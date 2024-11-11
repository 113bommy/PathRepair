#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int q, s1, s2, s3, w, m, e;
  vector<long long int> v;
  cin >> q;
  long long int n;
  for (int i = 0; i < q; i++) {
    cin >> n;
    long long int a[n];
    s1 = 0;
    s2 = 0;
    s3 = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      if (a[j] % 3 == 0) {
        s3++;
      } else if (a[j] % 3 == 1) {
        s1++;
      } else if (a[j] % 3 == 2) {
        s2++;
      }
    }
    w = (s3 + min(s1, s2));
    m = s1;
    e = s2;
    m -= min(s1, s2);
    e -= min(s1, s2);
    s1 = m;
    s2 = e;
    w += s1 / 3;
    w += s2 / 3;
    v.push_back(w);
  }
  for (int i = 0; i < q; i++) {
    cout << v[i] << endl;
  }
}
