#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(const int64_t& a, const int64_t& b) { return a > b; }
};
bool customS(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
bool customS2(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
  return (a.first) < (b.first);
}
class CompareDist {
 public:
  bool operator()(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    return a.first < b.first;
  }
};
int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
double gcdfloat(double a, double b) {
  if (a < b) return gcd(b, a);
  if (fabs(b) < 0.001)
    return a;
  else
    return (gcd(b, a - floor(a / b) * b));
}
int64_t LCA(int64_t a, int64_t b) {
  while (a != b) {
    if (b > a) {
      swap(a, b);
    }
    a /= 2;
  }
  return a;
}
map<int64_t, int64_t> hash1;
bool check(int c, int d) {
  string a = to_string(c), b = to_string(d);
  int i;
  for (i = 0; i < a.length(); i++) {
    if (a[i] == '7') return true;
  }
  for (i = 0; i < b.length(); i++) {
    if (b[i] == '7') return true;
  }
  return false;
}
vector<int64_t> ra(int64_t n) {
  vector<int64_t> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  return arr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t i, j, a = 0, b = 0, c = 0, d = 0, n, m, k, sum = 0, x, y, flag = 0,
                zero = 0, ans = INT64_MAX;
  string s, newS;
  cin >> n >> m;
  map<int64_t, int64_t> hash;
  for (i = 0; i < m; i++) {
    int64_t maxi = 0, pos;
    for (j = 0; j < n; j++) {
      cin >> a;
      if (a > maxi) {
        maxi = a;
        pos = j;
      }
    }
    hash[pos]++;
  }
  int64_t maxi = 0, pos;
  for (auto it : hash) {
    if (it.second > maxi) {
      maxi = it.second;
      pos = it.first;
    } else if (it.second == maxi) {
      pos = min(pos, it.first);
    }
  }
  cout << pos + 1 << "\n";
  return 0;
}
