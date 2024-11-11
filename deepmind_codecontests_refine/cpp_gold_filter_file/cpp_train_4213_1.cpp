#include <bits/stdc++.h>
using namespace std;
long long powmod(long long b, long long p, long long m) {
  long long r = 1;
  for (long long i = (1ll << 62); i; i >>= 1) {
    r *= r;
    r %= m;
    if (p & i) {
      r *= b;
      r %= m;
    }
  }
  return r;
}
vector<pair<int, string> > VV;
long long Value[20];
long long Length[20];
bool notLead[20];
string inp;
long long eval(string &str) {
  long long ret = 0;
  for (auto x : str) {
    if (x != ' ') ret *= powmod(10, Length[x - '0'], 1000000007);
    ret += (x == ' ' ? 0 : Value[x - '0']);
    ret %= 1000000007;
  }
  return ret;
}
int main() {
  for (auto i = 0; i < (11); i++) Value[i] = i, Length[i] = 1;
  ios_base::sync_with_stdio(0);
  cin >> inp;
  int q;
  cin >> q;
  while (q--) {
    string query;
    cin >> query;
    int idx = query[0] - '0';
    query = query.substr(3, ((int)query.size()) - 3);
    if (!((int)query.size())) query += ' ';
    VV.push_back({idx, query});
  }
  reverse(VV.begin(), VV.end());
  for (auto x : VV) {
    long long temp = eval(x.second);
    Value[x.first] = temp;
    long long ttt = 0;
    for (auto k : x.second) {
      if (k != ' ') ttt += Length[k - '0'];
      ttt %= (1000000007 - 1);
    }
    Length[x.first] = ttt;
  }
  cout << eval(inp) << endl;
  return 0;
}
