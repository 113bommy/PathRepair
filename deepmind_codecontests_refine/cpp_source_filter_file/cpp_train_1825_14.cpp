#include <bits/stdc++.h>
using namespace std;
const long long base = 139;
const long long M = 1000012309;
long long p[200007];
vector<pair<long long, char> > vp1;
vector<pair<long long, char> > vp2;
long long hashtable[200007], hv, cnt = 0;
void pcal() {
  p[0] = 1;
  for (long long i = 1; i < 200007; ++i) p[i] = (p[i - 1] * base) % M;
}
void hashfunc() {
  hashtable[0] = (vp1[0].first * vp1[0].second) % M;
  ;
  long long sz1 = vp1.size();
  long long sz2 = vp2.size() - 2;
  long long sz3 = vp2.size();
  for (long long i = 1; i < sz1; ++i) {
    long long val = (vp1[i].first * vp1[i].second) % M;
    hashtable[i] = ((hashtable[i - 1] * base) % M + val) % M;
  }
  for (long long i = 0; i < sz1 - 1; ++i) {
    long long l = i + 1;
    long long r = i + sz2;
    if (vp1[i].second == vp2[0].second && vp1[i].first >= vp2[0].first &&
        r < sz1 - 1) {
      long long bad = (hashtable[l - 1] * p[r - l + 1]) % M;
      long long check = (hashtable[r] - bad + M) % M;
      if (check == hv && vp1[r + 1].second == vp2[sz3 - 1].second &&
          vp1[r + 1].first >= vp2[sz3 - 1].first)
        cnt++;
    }
  }
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long d;
  char c, a;
  pcal();
  for (long long i = 0; i < n; ++i) {
    cin >> d >> c >> a;
    if (i == 0)
      vp1.push_back({d, a});
    else {
      long long sz = vp1.size();
      if (a == vp1[sz - 1].second)
        vp1[sz - 1].first += d;
      else
        vp1.push_back({d, a});
    }
  }
  for (long long i = 0; i < m; ++i) {
    cin >> d >> c >> a;
    if (i == 0)
      vp2.push_back({d, a});
    else {
      long long sz = vp2.size();
      if (a == vp2[sz - 1].second)
        vp2[sz - 1].first += d;
      else
        vp2.push_back({d, a});
    }
  }
  if (vp1.size() < vp2.size()) {
    cout << 0 << endl;
    return 0;
  } else if (vp2.size() == 1) {
    long long sz1 = vp1.size();
    cnt = 0;
    for (long long i = 0; i < sz1 - 1; ++i) {
      if (vp2[0].second == vp1[i].second && vp2[0].first <= vp1[i].first)
        cnt += vp1[i].first - vp2[0].first + 1;
    }
    cout << cnt << endl;
  } else if (vp2.size() == 2) {
    long long sz1 = vp1.size();
    cnt = 0;
    for (long long i = 0; i < sz1 - 11; ++i) {
      if (vp2[0].second == vp1[i].second && vp2[1].second == vp1[i + 1].second)
        if (vp2[0].first <= vp1[i].first && vp2[1].first <= vp1[i + 1].first)
          cnt++;
    }
    cout << cnt << endl;
  } else if (vp2.size() > 2) {
    long long sz = vp2.size();
    cnt = 0;
    hv = (vp2[0].first * vp2[0].second) % M;
    for (long long i = 1; i < sz - 1; ++i) {
      long long d = vp2[i].first;
      long long a = vp2[i].second;
      long long val = (d * a) % M;
      hv = ((hv * base) % M + val) % M;
    }
    long long bad = ((vp2[0].first * vp2[0].second) % M * p[sz - 2]) % M;
    hv = (hv - bad + M) % M;
    hashfunc();
    cout << cnt << endl;
  }
}
