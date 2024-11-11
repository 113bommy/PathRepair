#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int MaxN = int(2e5) + 256;
const int MOD = int(1e9) + 7;
template <typename T>
inline T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
inline bool Palindrome(const string& s) {
  return equal(s.begin(), s.end(), s.rbegin());
}
vector<vector<int> > get(int s) {
  int last = 1;
  vector<vector<int> > v;
  for (int i = 1; i <= s + 1; ++i) {
    vector<int> t;
    for (int j = 0; j < i - 1; ++j) t.push_back(v[j][i - 2]);
    for (int j = i; j <= s; ++j) t.push_back(last++);
    v.push_back(t);
  }
  return v;
}
int main() {
  int n;
  scanf("%d", &n);
  int s = 1;
  for (s = 1;; ++s) {
    if (1ll * s * (s + 1) / 2 >= n) break;
  }
  --s;
  vector<vector<int> > v = get(s);
  printf("%d\n", (int)v.size());
  for (auto it : v) {
    for (auto jt : it) printf("%d ", jt);
    printf("\n");
  }
  return 0;
}
