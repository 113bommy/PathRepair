#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const long long int MODL = 1e9 + 7;
map<pair<long long int, long long int>, pair<long long int, long long int> > dp;
vector<long long int> vect(100000);
pair<long long int, long long int> ncandies(long long int l, long long int r) {
  pair<long long int, long long int> basep;
  basep.first = l, basep.second = r;
  pair<long long int, long long int> ansp;
  auto it = dp.find(basep);
  if (it != dp.end()) {
    ansp.first = (it->second).first;
    ansp.second = (it->second).second;
    return ansp;
  }
  if (l == r) {
    ansp.first = 0;
    ansp.second = vect[l];
    return ansp;
  }
  long long int candies, sum;
  pair<long long int, long long int> pr1, pr2;
  pr1 = ncandies(l, l + ((r - l + 1) / 2) - 1);
  pr2 = ncandies(l + ((r - l + 1) / 2), r);
  candies = pr1.first + pr2.first;
  sum = pr1.second + pr2.second;
  if (sum >= 10) {
    candies++;
    sum = sum % 10;
  }
  ansp.first = candies;
  ansp.second = sum;
  dp.insert(make_pair(basep, ansp));
  return ansp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long int n, q, l, r, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> vect[i];
  }
  cin >> q;
  pair<int, int> tempp;
  while (q--) {
    cin >> l >> r;
    tempp = ncandies(l, r);
    cout << tempp.first << "\n";
  }
  return 0;
}
