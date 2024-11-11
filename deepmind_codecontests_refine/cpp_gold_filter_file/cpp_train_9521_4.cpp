#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
long long powMod(long long a, long long k, long long n) {
  long long ret = 1;
  for (long long pow = a; k > 0; k >>= 1, pow = (pow * pow) % n)
    if (k & 1) ret = (ret * pow) % n;
  return ret;
}
string s;
vector<string> sq;
pair<long long, long long> dig[11];
pair<long long, long long> uni(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return make_pair(
      (a.first + b.first) % (1000000007 - 1),
      (a.second * powMod(10, b.first, 1000000007) + b.second) % 1000000007);
}
pair<long long, long long> merge(string at) {
  pair<long long, long long> foo = make_pair(0LL, 0LL);
  for (int i = at.size() - 1; i >= 0; --i) foo = uni(dig[at[i] - '0'], foo);
  return foo;
}
int main() {
  cin >> s;
  int q;
  cin >> q;
  while (q--) {
    string foo;
    cin >> foo;
    sq.push_back(foo);
  }
  for (int i = 0; i < 10; ++i) dig[i] = make_pair(1LL, (long long)i);
  for (int i = sq.size() - 1; i >= 0; --i)
    dig[sq[i][0] - '0'] = merge(sq[i].substr(3));
  cout << merge(s).second % 1000000007 << endl;
  return 0;
}
