#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& out, vector<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, set<T> v) {
  for (T t : v) out << t << ' ';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, pair<T, T> v) {
  out << v.first << ' ' << v.second;
  return out;
}
long long pow(long long a, int x) {
  if (x == 0) return 1;
  if (x & 1) return pow(a, x - 1) * a;
  long long temp = pow(a, x >> 1);
  return temp * temp;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<bool> tot(1000000 + 1, true);
  vector<long long> unele, ele;
  vector<vector<long long> > po(65);
  long long lastnum = 1e18;
  for (int i = 2; i <= 1000000; ++i) {
    if (tot[i]) {
      ele.push_back(i);
      for (long long j = 1ll * i * i; j <= 1000000000; j *= i) {
        unele.push_back(j);
        if (j <= 1000000) tot[(int)j] = false;
      }
    }
  }
  po[0].assign(ele.size() + 1, 1);
  for (int i = 1; i <= 64; ++i) {
    for (int j = 0; j < ele.size(); ++j) {
      long long t = ele[j];
      if (po[i - 1].size() == (long long)j || lastnum / po[i - 1][j] < t) break;
      po[i].push_back(po[i - 1][j] * t);
    }
  }
  sort(unele.begin(), unele.end());
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long sq = sqrt(n);
    if ((sq + 1) * (sq + 1) <= n) sq++;
    long long res = 0;
    int num = lower_bound(unele.begin(), unele.end(), sq) - unele.begin();
    if (num == unele.size() || unele[num] > sq) num--;
    res += sq - 1 - num - 1;
    for (int i = 3; i <= 64; ++i) {
      int pos = upper_bound(po[i].begin(), po[i].end(), n) - po[i].begin();
      res += pos;
    }
    cout << n - 1 - res << '\n';
  }
  return 0;
}
