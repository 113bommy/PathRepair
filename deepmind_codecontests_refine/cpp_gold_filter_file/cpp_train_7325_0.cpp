#include <bits/stdc++.h>
using namespace std;
vector<int> ld;
int mxn = 100005;
void sieve() {
  ld.resize(mxn);
  ld[0] = 1;
  for (int i = 0; i < mxn; i++) ld[i] = i;
  for (int i = 2; i * i < mxn; i++)
    if (ld[i] == i)
      for (int j = i * i; j < mxn; j += i)
        if (ld[j] == j) ld[j] = i;
}
vector<pair<int, int> > facto(int n) {
  vector<pair<int, int> > ans;
  while (n > 1) {
    pair<int, int> p = make_pair(ld[n], 0);
    int num = ld[n];
    while (ld[n] == num) {
      n /= num;
      p.second++;
    }
    ans.push_back(p);
  }
  return ans;
}
vector<int> ans;
void solve(const vector<pair<int, int> >& factros, int pos, int num) {
  if ((int)factros.size() == pos) {
    ans.push_back(num);
    return;
  }
  int cur = num;
  for (int i = 0; i <= factros[pos].second; i++) {
    solve(factros, pos + 1, cur);
    cur *= factros[pos].first;
  }
}
vector<int> getD(int n) {
  ans.clear();
  vector<pair<int, int> > factors = facto(n);
  solve(factors, 0, 1);
  return ans;
}
const int mod = 1000000007;
long long fp(long long b, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans *= b, ans %= mod;
    p /= 2;
    b *= b;
    b %= mod;
  }
  return ans;
}
int n;
vector<int> vec;
int main() {
  sieve();
  cin >> n;
  vec.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  int sz = vec.size() - 1;
  long long sm = 0, smextra = 1;
  for (int val = 1; val <= vec[sz]; val++) {
    long long ans = 1, extra = 1;
    vector<int> divisors = getD(val);
    sort(divisors.rbegin(), divisors.rend());
    vector<int> ends;
    for (int i = 0; i < (int)divisors.size(); i++) {
      int lp = lower_bound(vec.begin(), vec.end(), divisors[i]) - vec.begin();
      ends.push_back(lp);
    }
    int lst = vec.size();
    for (int i = 0; i < (int)divisors.size(); i++) {
      int p = lst - ends[i];
      lst = ends[i];
      int b = divisors.size() - i;
      ans *= fp(b, p);
      ans %= mod;
    }
    divisors.erase(divisors.begin());
    ends.erase(ends.begin());
    lst = vec.size();
    for (int i = 0; i < (int)divisors.size(); i++) {
      int p = lst - ends[i];
      lst = ends[i];
      int b = divisors.size() - i;
      extra *= fp(b, p);
      extra %= mod;
    }
    sm += ans;
    smextra += extra;
    sm %= mod;
    smextra %= mod;
  }
  long long out = (sm - smextra + mod + 2) % mod;
  cout << out << endl;
}
