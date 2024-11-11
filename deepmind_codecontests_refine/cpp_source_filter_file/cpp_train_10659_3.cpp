#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T a) {
  return a < 0 ? -a : a;
}
int binpow(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res *= a;
    a *= a;
    n >>= 1;
  }
  return res;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v.push_back(t - 1);
  }
  --k;
  int size = v.size();
  int bp = -1;
  vector<int> qs;
  for (int i = 0; i < size; ++i) {
    if (v[i] == -1) {
      if (i == k) {
        bp = 0;
        continue;
      }
      int last = i;
      int s = 1;
      int j = 0;
      for (; j < size; ++j) {
        if (v[j] == last) {
          if (j == k) {
            bp = s;
            j = -1;
            break;
          }
          s++;
          last = j;
          j = 0;
        }
      }
      if (j != -1) qs.push_back(s);
    }
  }
  set<int> full;
  set<int> temp;
  for (int i = 0; i < qs.size(); ++i) {
    temp.insert(qs[i]);
    set<int>::iterator it = full.begin();
    set<int>::iterator end = full.end();
    for (; it != end; ++it) temp.insert(*it + qs[i]);
    full.insert(temp.begin(), temp.end());
    temp.clear();
  }
  cout << bp + 1 << endl;
  set<int>::iterator it = full.begin();
  set<int>::iterator end = full.end();
  for (; it != end; ++it) cout << *it + bp + 1 << endl;
  return 0;
}
