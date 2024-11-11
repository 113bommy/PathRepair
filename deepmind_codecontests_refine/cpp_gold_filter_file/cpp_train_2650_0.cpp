#include <bits/stdc++.h>
using namespace std;
long long f(vector<long long> nums) {
  long long k = 0;
  for (auto i : nums) k ^= i;
  return k;
}
void doo(long long l, long long r, long long k) {
  if (r - l + 1 >= 5) {
    if (k >= 4) {
      if (l % 2) ++l;
      cout << "0\n4\n";
      for (int(i) = 0; (i) < (4); (i)++) cout << l + i << " ";
    } else if (k == 3) {
      long long d = -1;
      for (long long lk = r; lk; lk /= 2) {
        ++d;
      }
      long long top = 1LL << d;
      for (; top; top /= 2) {
        long long x = top | top / 2;
        long long y = x - 1;
        long long z = x ^ y;
        if (l <= x && l <= y && l <= z && r >= x && r >= y && r >= z) {
          cout << "0\n3\n" << x << " " << y << " " << z;
          return;
        }
      }
      if (l % 2) ++l;
      cout << "1\n2\n";
      for (int(i) = 0; (i) < (2); (i)++) cout << l + i << " ";
    } else if (k == 2) {
      if (l % 2) ++l;
      cout << "1\n2\n";
      for (int(i) = 0; (i) < (2); (i)++) cout << l + i << " ";
    } else {
      cout << l << "\n1\n" << l;
    }
  } else {
    vector<vector<long long>> combs;
    for (int(i) = 0; (i) < (1 << (r - l + 1)); (i)++) {
      if (!i) continue;
      vector<long long> s;
      for (int(j) = 0; (j) < (r - l + 1); (j)++) {
        if (i & (1 << j)) {
          s.push_back(l + j);
        }
      }
      if (s.size() <= k) combs.push_back(s);
    }
    auto it = min_element((combs).begin(), (combs).end(),
                          [](vector<long long> a1, vector<long long> a2) {
                            return f(a1) < f(a2);
                          });
    cout << f(*it) << endl;
    cout << it->size() << endl;
    for (int(i) = 0; (i) < (it->size()); (i)++) cout << (*it)[i] << " ";
  }
}
void solve() {
  long long l, r, k;
  cin >> l >> r >> k;
  doo(l, r, k);
}
int main() {
  solve();
  return 0;
}
