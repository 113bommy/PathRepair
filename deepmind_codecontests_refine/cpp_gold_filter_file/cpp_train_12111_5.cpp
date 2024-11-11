#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  long long n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  a.push_back(-a.back());
  vector<pair<int, long long> > c;
  for (int i = 1, s = 0; i < a.size(); i++)
    if (a[i] != a[s]) {
      c.push_back(make_pair(a[s], i - s));
      s = i;
    }
  long long p = 0;
  for (int i = 0; i < c.size(); i++) {
    long long t = c[i].second * n;
    if (p + t >= k) {
      for (int j = 0; j < c.size(); j++) {
        t = c[i].second * c[j].second;
        if (p + t >= k) {
          cout << c[i].first << " " << c[j].first << endl;
          return 0;
        }
        p += t;
      }
    }
    p += t;
  }
  return 0;
}
