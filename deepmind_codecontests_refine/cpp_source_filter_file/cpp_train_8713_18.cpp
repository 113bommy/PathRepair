#include <bits/stdc++.h>
const long long int loo = 2e18;
const int ioo = 2e9;
const int md = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1);
using namespace std;
int n;
map<string, int> mp;
vector<string> v;
bool is[6];
int main(void) {
  v.push_back("Power");
  v.push_back("Time");
  v.push_back("Space");
  v.push_back("Soul");
  v.push_back("Reality");
  v.push_back("Mind");
  mp["purple"] = 0;
  mp["green"] = 1;
  mp["blue"] = 2;
  mp["orange"] = 3;
  mp["red"] = 4;
  mp["yellow"] = 5;
  scanf("%d", &n);
  for (int i = 0; i < 6; i++) {
    string s;
    cin >> s;
    is[mp[s]] = 1;
  }
  cout << 6 - n << endl;
  for (int i = 0; i < 6; i++) {
    if (!is[i]) cout << v[i] << endl;
  }
  return 0;
}
