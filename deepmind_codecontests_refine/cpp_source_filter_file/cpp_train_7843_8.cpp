#include <bits/stdc++.h>
using namespace std;
vector<long long> vn;
bool bs(long long n, long long len) {
  long long low = 0, hi = len - 1, mid;
  while (low <= hi) {
    mid = (low + hi) / 2;
    if (vn[mid] == n)
      return true;
    else if (n > vn[mid])
      low = mid + 1;
    else
      hi = mid - 1;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x;
  cin >> x;
  long long n = x;
  while (n != 0) {
    vn.push_back(n % 10);
    n /= 10;
  }
  sort(vn.begin(), vn.end());
  long long l = vn.size(), cnt = 0;
  vector<pair<long long, long long> > v;
  for (long long i = 1; i <= sqrt(x); i++) {
    if (!(x % i)) v.push_back(make_pair(x / i, i));
  }
  for (long long i = 0; i < v.size(); i++) {
    long long nc = v[i].first;
    while (nc != 0) {
      if (bs(nc % 10, l) == true) {
        cnt += 1;
        break;
      }
      nc /= 10;
    }
    if (v[i].first != v[i].second) {
      long long ncc = v[i].second;
      while (ncc != 0) {
        if (bs(ncc, l) == true) {
          cnt += 1;
          break;
        }
        ncc /= 10;
      }
    }
  }
  cout << cnt;
  return 0;
}
