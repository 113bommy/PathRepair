#include <bits/stdc++.h>
using namespace std;
long long a[4000009];
map<long long, long long> mp;
map<long long, long long> mp1;
map<long long, long long> mp2;
struct ss {
  long long a, b, c;
};
bool acompare(ss lhs, ss rhs) { return lhs.a < rhs.a; }
ss bs[200009];
int main() {
  cin.sync_with_stdio(false);
  long long i, j, k, l, c, v, ba, bv[1000], aa[1009], bb[1000], n, m, r, t, e,
      f;
  long long x1, x2, y1, y2, x3, x4, x5, x6;
  string s, s1, s2, s3, ss[10000];
  while (cin >> n) {
    v = 0;
    c = -1e18;
    l = 0;
    vector<long long> vc;
    vector<long long> vc1;
    vector<long long> vc2;
    for (i = 1; i <= n; i++) {
      cin >> m;
      if (m < 0) {
        v++;
        if (m > c) {
          c = m;
          k = i;
          l = v - 1;
        }
        vc.push_back(i);
      } else if (m > 0) {
        vc2.push_back(i);
      } else {
        vc1.push_back(i);
      }
    }
    if (v % 2 == 1) {
      vc.erase(vc.begin() + l);
      t = vc.size();
      m = t;
      for (j = 0; j < m - 1; j++) {
        cout << 1 << " " << vc[j] << " " << vc[j + 1] << endl;
      }
      m = vc1.size();
      for (i = 0; i < m - 1; i++) {
        cout << 1 << " " << vc1[i] << " " << vc1[i + 1] << endl;
      }
      if ((vc2.size() > 0 || vc.size() > 0) && m > 0) {
        cout << 1 << " " << min(k, vc1[i]) << " " << max(k, vc1[i]) << endl;
        cout << 2 << " " << max(k, vc1[i]) << endl;
      } else {
        cout << 2 << " " << k << endl;
      }
      m = vc2.size();
      for (i = 0; i < m - 1; i++) {
        cout << 1 << " " << vc2[i] << " " << vc2[i + 1] << endl;
      }
      if (t > 0 && m > 0) {
        cout << 1 << " " << min(vc2[i], vc[j]) << " " << max(vc2[i], vc[j])
             << endl;
      }
    } else {
      t = vc.size();
      m = t;
      for (j = 0; j < m - 1; j++) {
        cout << 1 << " " << vc[j] << " " << vc[j + 1] << endl;
      }
      m = vc1.size();
      for (i = 0; i < m - 1; i++) {
        cout << 1 << " " << vc1[i] << " " << vc1[i + 1] << endl;
      }
      if ((vc2.size() > 0 || vc.size() > 0) && m > 0) {
        cout << 2 << " " << vc1[i] << endl;
      }
      m = vc2.size();
      for (i = 0; i < m - 1; i++) {
        cout << 1 << " " << vc2[i] << " " << vc2[i + 1] << endl;
      }
      if (t > 0 && m > 0) {
        cout << 1 << " " << min(vc2[i], vc[j]) << " " << max(vc2[i], vc[j])
             << endl;
      }
    }
  }
}
