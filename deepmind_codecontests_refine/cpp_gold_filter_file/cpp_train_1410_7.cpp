#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 1];
set<pair<long long, long long> > ms;
std::set<pair<long long, long long> >::iterator it1;
std::set<pair<long long, long long> >::iterator it2;
bool cmp(const long long p, const pair<long long, long long> q) {
  return p < q.first;
}
bool cmp2(const long long p, const pair<long long, long long> q) {
  return p > q.first;
}
int main() {
  long long n, x;
  cin >> n;
  cin >> x;
  ms.insert(make_pair(x, 0LL));
  for (long long i = 1; i < n; i++) {
    cin >> x;
    it1 = ms.upper_bound(make_pair(x, -1LL));
    if (it1 == ms.end()) {
      it2 = it1;
      it2--;
      cout << (*it2).first << " ";
    } else if (it1 == ms.begin()) {
      cout << (*it1).first << " ";
    } else {
      it2 = it1;
      it2--;
      long long q = (*it2).second;
      long long p = (*it1).second;
      if (p > q)
        cout << (*it1).first << " ";
      else
        cout << (*it2).first << " ";
    }
    ms.insert(make_pair(x, i));
  }
}
