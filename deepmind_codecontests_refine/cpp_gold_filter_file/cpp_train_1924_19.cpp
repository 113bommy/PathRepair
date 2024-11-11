#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int den;
int inv() {
  vector<int> aa = a;
  int ret = 0;
  for (int i = 1; i <= a.size(); i++) {
    int ind = find(aa.begin(), aa.end(), i) - aa.begin();
    aa.erase(aa.begin() + ind);
    ret += ind;
  }
  return ret;
}
double go(int k) {
  if (!k) return inv();
  double ret = 0;
  for (int i = 0; i < a.size(); i++) {
    for (int j = i; j < a.size(); j++) {
      reverse(a.begin() + i, a.begin() + j + 1);
      ret += go(k - 1) * 1.0 / den;
      reverse(a.begin() + i, a.begin() + j + 1);
    }
  }
  return ret;
}
int main() {
  int n, k;
  while (cin >> n >> k) {
    den = n * (n + 1) / 2;
    a.resize(n);
    for (int i = 0; i < n; scanf("%d", &a[i++]))
      ;
    if (n == 1) {
      cout << setprecision(12) << fixed << 0.000000000000000000000 << endl;
      continue;
    }
    cout << setprecision(12) << fixed << go(k) << endl;
  }
  return 0;
}
