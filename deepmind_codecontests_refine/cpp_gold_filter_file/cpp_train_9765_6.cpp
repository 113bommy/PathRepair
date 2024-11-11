#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<string, ll> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    m[s]++;
  }
  ll r = 0;
  for (auto e : m) r += e.second * (e.second - 1) / 2;
  cout << r << endl;
}
