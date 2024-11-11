#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debugv(vector<T> arr) {
  for (auto t : arr) cout << t << " ";
  cout << "\n";
}
const int maxn = 1e5 + 1;
long long arr[maxn], n, m, t, k;
unordered_map<long long, long long> u;
long long __min(long long a, long long b) { return a < b ? a : b; }
long long __max(long long a, long long b) { return a > b ? a : b; }
string s;
bool pos(long long d) {
  if (d < 1) return false;
  long long mr = d - 1;
  long long i = 0;
  while (i < n) {
    long long j = mr;
    if (mr >= n) return true;
    while (i <= j) {
      if (s[i] == 'R') mr = __max(mr, i + d);
      if (mr >= n) return true;
      i++;
    }
    if (i > mr) return false;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    long long l = 0;
    long long r = n + 1;
    long long res;
    while (l <= r) {
      long long m = l + ((r - l) >> 1);
      if (pos(m)) {
        res = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    cout << res << "\n";
  }
}
