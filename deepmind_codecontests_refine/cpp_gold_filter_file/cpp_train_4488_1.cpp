#include <bits/stdc++.h>
using namespace std;
map<char, long long> mp, mp2;
vector<pair<char, bool>> v1;
vector<long long> v;
pair<long long, long long> arr[200008];
pair<long long, bool> b[4] = {{2, 1}, {3, 1}, {5, 1}, {7, 1}};
pair<long long, bool> c[4];
vector<long long>::iterator it;
set<long long> second;
int main() {
  size_t found;
  long long c1 = 0, c2 = 0, g = 1, h = 1, z = 4, k = 0, maxi = 1e10, p = 2,
            msize, sum = 0, sum1 = 0, sumi = 0, sumf = 0, ans = 0;
  long long n, m, e, count = 0, a, b, in, mod;
  string s1 = "", s20 = "", x = "", sx = "";
  bool t = 0, t1 = 0;
  cin >> a >> b;
  cin >> x;
  for (int i = 0; i < x.length(); i++) {
    mp[x[i]]++;
  }
  if (mp.size() < b) {
    cout << 0;
    return 0;
  }
  for (auto i : mp) {
    if (i.second < maxi) {
      maxi = i.second;
    }
  }
  cout << maxi * b;
}
