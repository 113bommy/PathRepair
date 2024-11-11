#include <bits/stdc++.h>
using namespace std;
template <typename T>
void sort(T &a) {
  sort(a.begin(), a.end());
}
template <typename T>
void unique(T &a) {
  a.resize(unique(a.begin(), a.end()) - a.begin());
}
template <typename T>
void reverse(T &a) {
  reverse(a.begin(), a.end());
}
const long long INF = 9023372036854775807ll;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    multiset<long long> s;
    long long mn = INF;
    for (long long i = 0; i < n; ++i) {
      long long x;
      cin >> x;
      mn = min(x, mn);
      s.insert(x);
    }
    s.erase(s.find(mn));
    long long c = 0;
    while (*s.begin() <= k) {
      long long nw = *s.begin() + mn;
      s.erase(s.begin());
      s.insert(nw);
      ++c;
    }
    cout << c << '\n';
  }
  return 0;
}
