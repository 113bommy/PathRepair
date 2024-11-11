#include <bits/stdc++.h>
using namespace std;
int solv() {
  int n, i;
  cin >> n;
  vector<int> a;
  int z = 0, s = 0, b;
  vector<int> r, rr, rrr;
  for (i = 0; i < n; i++) {
    cin >> b;
    if (!b) z = 1;
    s += b;
    a.push_back(b);
    if (b % 3 == 1)
      r.push_back(b);
    else if (b % 3 == 2)
      rr.push_back(b);
    else
      rrr.push_back(b);
  }
  if (s == 0) {
    cout << "0";
    return 0;
  }
  int nr = r.size(), nrr = rr.size();
  sort(r.begin(), r.end());
  sort(rr.begin(), rr.end());
  if (!z) {
    cout << "-1";
    return 0;
  }
  if (s % 3 == 0) {
    sort(a.begin(), a.end(), greater<int>());
    for (i = 0; i < n; i++) cout << a[i];
    return 0;
  }
  a.clear();
  if (s % 3 == 1) {
    if (nr) {
      r.erase(r.begin());
    } else if (nrr >= 2) {
      rr.erase(rr.begin());
      rr.erase(rr.begin());
    } else {
      cout << "-1";
      return 0;
    }
  } else {
    if (nrr) {
      rr.erase(rr.begin());
    } else if (nr >= 2) {
      r.erase(r.begin());
      r.erase(r.begin());
    } else {
      cout << "-1";
      return 0;
    }
  }
  s = 0;
  for (i = 0; i < r.size(); i++) a.push_back(r[i]);
  for (i = 0; i < rr.size(); i++) a.push_back(rr[i]);
  for (i = 0; i < rrr.size(); i++) a.push_back(rrr[i]);
  sort(a.rbegin(), a.rend());
  for (i = 0; i < a.size(); i++) s += a[i];
  if (s == 0) {
    cout << "0";
    return 0;
  }
  for (i = 0; i < a.size(); i++) cout << a[i];
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int testcases = 1;
  while (testcases--) {
    solv();
  }
}
