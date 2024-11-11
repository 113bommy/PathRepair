#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, m, k, q;
  cin >> n >> m >> k >> q;
  pair<long long int, long long int> p = {0, 0};
  vector<pair<long long int, long long int>> v1(n + 1, p);
  vector<pair<long long int, long long int>> v2(n + 1, p);
  set<long long int> s1;
  for (long long int i = 0; i < k; i++) {
    long long int a, b;
    cin >> a >> b;
    s1.insert(a);
    if (v1[a].first == 0) {
      v1[a] = {b, b};
      continue;
    }
    if (b > v1[a].second) {
      v1[a] = {v1[a].first, b};
    } else if (b < v1[a].first) {
      v1[a] = {b, v1[a].second};
    }
  }
  set<long long int> s;
  for (long long int i = 0; i < q; i++) {
    long long int a;
    cin >> a;
    s.insert(a);
  }
  long long int ind = -1;
  for (auto i : s1) {
    if (i == *(s1.begin())) {
      long long int a = *(s.begin());
      long long int b = *(s.rbegin());
      long long int l = v1[i].first;
      long long int r = v1[i].second;
      if (i == 1) {
        v2[i] = {2 * (v1[i].second - 1), v1[i].second - 1};
        ind = i;
        continue;
      }
      long long int a1 = (a - 1 + i - 1 + abs(r - a) + abs(r - l));
      long long int a2 = (a - 1 + i - 1 + abs(a - l) + abs(r - l));
      long long int a3 = (b - 1 + i - 1 + abs(r - b) + abs(r - l));
      long long int a4 = (b - 1 + i - 1 + abs(l - b) + abs(r - l));
      v2[i] = {min(a1, a3), min(a2, a4)};
      ind = i;
    } else {
      long long int p, q, r, s1;
      auto a = (s.lower_bound(v1[ind].first));
      auto b = (s.upper_bound(v1[ind].first));
      long long int l1 = v1[i].first;
      long long int r1 = v1[i].second;
      long long int c = v1[ind].first;
      long long int d = v1[ind].second;
      if (*a == v1[ind].first) {
        p = *a;
        q = *a;
      } else if (b == s.end()) {
        p = *(--a);
        q = *(--a);
      } else if (a == s.begin()) {
        p = *a;
        q = *a;
      } else {
        p = *(--a);
        q = *b;
      }
      a = (s.lower_bound(v1[ind].second));
      b = (s.upper_bound(v1[ind].second));
      if (*a == v1[ind].second) {
        r = *a;
        s1 = *a;
      } else if (b == s.end()) {
        r = *(--a);
        s1 = *(--a);
      } else if (a == s.begin()) {
        r = *a;
        s1 = *a;
      } else {
        r = *(--a);
        s1 = *b;
      }
      long long int a1 =
          (abs(p - c) + i - ind + abs(p - r1) + abs(l1 - r1)) + v2[ind].first;
      long long int a2 =
          (abs(q - c) + i - ind + abs(q - r1) + abs(l1 - r1)) + v2[ind].first;
      long long int a3 =
          (abs(r - c) + i - ind + abs(r - r1) + abs(l1 - r1)) + v2[ind].second;
      long long int a4 = (abs(s1 - c) + i - ind + abs(s1 - r1) + abs(l1 - r1)) +
                         v2[ind].second;
      long long int x = min(min(a1, a2), min(a3, a4));
      a1 = (abs(p - c) + i - ind + abs(p - l1) + abs(l1 - r1)) + v2[ind].first;
      a2 = (abs(q - c) + i - ind + abs(q - l1) + abs(l1 - r1)) + v2[ind].first;
      a3 = (abs(r - c) + i - ind + abs(r - l1) + abs(l1 - r1)) + v2[ind].second;
      a4 = (abs(s1 - c) + i - ind + abs(s1 - l1) + abs(l1 - r1)) +
           v2[ind].second;
      long long int y = min(min(a1, a2), min(a3, a4));
      v2[i] = {x, y};
      ind = i;
    }
  }
  cout << min(v2[*(s1.rbegin())].first, v2[*(s1.rbegin())].second) << "\n";
  return 0;
}
