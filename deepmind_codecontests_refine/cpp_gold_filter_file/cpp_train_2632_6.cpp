#include <bits/stdc++.h>
using namespace std;
struct comp {
  bool operator()(const int& lhs, const int& rhs) const { return lhs > rhs; }
};
struct comps {
  bool operator()(const string& lhs, const string& rhs) const {
    return lhs > rhs;
  }
};
bool f(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
int main() {
  int n;
  map<int, int> m;
  long long unsigned int x, y, z;
  long long unsigned int min = 10000000000LL, max = 0;
  scanf("%d", &n);
  for (int i = 1; i <= sqrt(n); i++)
    if (n % i == 0) m[i] = n / i;
  m[n] = 1;
  for (map<int, int>::iterator mi = m.begin(); mi != m.end(); mi++) {
    int k = (*mi).second;
    x = (*mi).first;
    map<int, int> mm;
    for (int i = 1; i <= sqrt(k); i++) {
      if (k % i == 0) mm[i] = k / i;
    }
    mm[k] = 1;
    for (map<int, int>::iterator mmi = mm.begin(); mmi != mm.end(); mmi++) {
      y = (*mmi).first;
      z = (*mmi).second;
      long long unsigned int res = (z + 2) * (2 * x + y + 2) + 2 * x * y;
      if (min > res) min = res;
      if (max < res) max = res;
    }
    mm.clear();
  }
  printf("%I64d %I64d", min, max);
  return 0;
}
