#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int xx = (int)1e6 + 1;
bool sortinrev(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.first > b.first);
}
long long int A[1000000];
long long int B[1000000];
map<long long int, vector<long long int> > ps;
map<string, long long int> mp;
void fun() {
  mp["01"] = 31;
  mp["02"] = 28;
  mp["03"] = 31;
  mp["04"] = 30;
  mp["05"] = 31;
  mp["06"] = 30;
  mp["07"] = 31;
  mp["08"] = 31;
  mp["09"] = 30;
  mp["10"] = 31;
  mp["11"] = 30;
  mp["12"] = 31;
}
map<string, long long int> cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  string s, result;
  cin >> s;
  long long int mx = 0;
  for (long long int i = 0; i < ((int)(s).size()) - 10; i++) {
    string h = s.substr(i, 10), x = h.substr(6, 4), y = h.substr(3, 2);
    if (h[0] >= '0' && h[1] >= '0' && h[2] == '-' && h[5] == '-' &&
        mp[y] != 0 && (x == "2013" || x == "2014" || x == "2015")) {
      long long int val = (h[0] - '0') * 10;
      val += (h[1] - '0');
      if (val <= mp[y] && val != 0) {
        cnt[h]++;
        if (cnt[h] > mx) result = h, mx = cnt[h];
      }
    }
  }
  cout << result << endl;
  return 0;
}
