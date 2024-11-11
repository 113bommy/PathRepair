#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
const long long LINF = 1e16;
const double pi = 3.1415926535897932;
const string endstr = "\n";
template <typename T>
T gcd(T a, T b) {
  return (a == 0) ? b : gcd(b % a, a);
}
template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
bool p_comp_fs(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first < p2.first;
};
bool p_comp_fg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.first > p2.first;
};
bool p_comp_ss(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second < p2.second;
};
bool p_comp_sg(const pair<long long, long long> p1,
               const pair<long long, long long> p2) {
  return p1.second > p2.second;
};
template <typename T>
vector<T> uniquen(vector<T> vec) {
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  return vec;
}
int main() {
  long long n, z;
  cin >> n >> z;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  };
  sort(a.begin(), a.end());
  long long ans = 0;
  long long l = (n + 1) / 2 - 1, r = n - 1;
  while (l >= 0 && l < r) {
    if (a[r] - a[l] >= z) {
      ans++;
      l--;
      r--;
      continue;
    } else {
      l--;
    }
  }
  cout << ans << endl;
  return 0;
}
