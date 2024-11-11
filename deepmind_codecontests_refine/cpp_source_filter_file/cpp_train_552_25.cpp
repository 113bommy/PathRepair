#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long MX = 2e5 + 10;
const long long MOD = 1000000007;
const long long MX2 = 9223372036854775806;
const long long MX3 = 100000 + 5;
vector<long long> A;
vector<pair<long long, long long> > vec;
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}
int main() {
  long long n, k;
  cin >> n >> k;
  ;
  vector<pair<long long, long long> > ve(n, pair<long long, long long>(0, 0));
  map<pair<long long, long long>, long long> m;
  for (long long i = 0; i < (long long)n; i++) {
    cin >> ve[i].first >> ve[i].second;
    m[{ve[i].first, ve[i].second}]++;
  }
  sort(ve.begin(), ve.end(), cmp);
  pair<long long, long long> a;
  a = {ve[k].first, ve[k].second};
  vector<pair<long long, long long> >::iterator it;
  cout << m[a];
}
