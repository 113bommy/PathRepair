#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 1e5 + 500;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
string s;
long long n;
vector<long long> sor[800];
pair<long long, long long> f(vector<long long> vec, long long k) {
  if (vec.size() == 0) {
    return make_pair(-inf, k);
  }
  for (long long i = 0; i < vec.size(); i++) {
    long long v = vec[i];
    sor[s[v]].push_back(v);
  }
  vec.clear();
  for (long long i = 'a'; i <= 'z'; i++) {
    for (long long j = 0; j < sor[i].size(); j++) {
      vec.push_back(sor[i][j]);
    }
    sor[i].clear();
  }
  vector<long long> cool;
  long long last = 0;
  pair<long long, long long> o;
  for (long long i = 1; i < vec.size(); i++) {
    if (s[vec[i - 1]] != s[vec[i]]) {
      for (long long j = last; j < i; j++) {
        if (vec[j] != n - 1) {
          cool.push_back(vec[j] + 1);
        }
      }
      if (k <= i - last) {
        return make_pair(vec[last] - 1, vec[last]);
      }
      k -= (i - last);
      o = f(cool, k);
      cool.clear();
      if (o.first == -inf) {
        k = o.second;
      } else {
        return make_pair(o.first - 1, o.second);
      }
      last = i;
    }
  }
  {
    long long i = vec.size();
    for (long long j = last; j < i; j++) {
      if (vec[j] != n - 1) {
        cool.push_back(vec[j] + 1);
      }
    }
    if (k <= i - last) {
      return make_pair(vec[last] - 1, vec[last]);
    }
    k -= (i - last);
    o = f(cool, k);
    cool.clear();
    if (o.first == -inf) {
      k = o.second;
    } else {
      return make_pair(o.first - 1, o.second);
    }
  }
  return make_pair(-inf, k);
}
int main() {
  cin >> s;
  long long k;
  cin >> k;
  ;
  n = s.size();
  vector<long long> vec;
  for (long long i = 0; i < n; i++) {
    vec.push_back(i);
  }
  pair<long long, long long> o = f(vec, k);
  if (o.first == -inf) {
    cout << "No such line\n";
  } else {
    for (long long i = o.first + 1; i <= o.second; i++) {
      cout << s[i];
    }
  }
}
