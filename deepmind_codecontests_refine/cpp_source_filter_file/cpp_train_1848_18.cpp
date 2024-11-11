#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
bool cmpManh(const std::pair<long long, long long>& l,
             const std::pair<long long, long long>& r) {
  return ((llabs(l.first) + llabs(l.second)) <
          (llabs(r.first) + llabs(r.second)));
}
int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main(void) {
  int t;
  scanf("%d", &t);
  long long int sum[200005];
  map<long long int, long long int> poss1;
  map<long long int, long long int> poss2;
  vector<long long> v[200005];
  int poss = 0;
  int anssum = 0;
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);
    long long int cur = 0;
    for (int j = 0; j < n; ++j) {
      int xx;
      scanf("%d", &xx);
      cur += xx;
      v[i].push_back(xx);
    }
    sum[i] = cur;
    if (poss == 0) {
      int sz = v[i].size();
      set<int> s;
      for (int j = 0; j < sz; ++j) {
        s.insert(v[i][j]);
      }
      for (auto k : s) {
        if (poss1.find(cur - k) != poss1.end()) {
          poss2[cur - k] = i;
          anssum = cur - k;
          poss = 1;
          break;
        } else {
          poss1[cur - k] = i;
        }
      }
    }
  }
  if (poss) {
    cout << "YES\n";
    long long int find1 = sum[poss1[anssum]] - anssum;
    long long int aa = 1;
    for (auto k : v[poss1[anssum]]) {
      if (k == find1) {
        break;
      }
      aa++;
    }
    long long int find2 = sum[poss2[anssum]] - anssum;
    long long int bb = 1;
    for (auto k : v[poss1[anssum]]) {
      if (k == find2) {
        break;
      }
      bb++;
    }
    cout << poss1[anssum] + 1 << " " << aa << '\n';
    cout << poss2[anssum] + 1 << " " << bb << '\n';
  } else {
    cout << "NO\n";
  }
  return (0);
}
