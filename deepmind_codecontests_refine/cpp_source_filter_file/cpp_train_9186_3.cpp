#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
bool sort1(const pair<pair<int, int>, int> &a,
           const pair<pair<int, int>, int> &b) {
  return (a.first.second < b.first.second);
}
bool sort2(const pair<pair<int, int>, int> &a,
           const pair<pair<int, int>, int> &b) {
  return (a.first.first > b.first.first);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long ma = 0;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          long long p = a[i] | a[j];
          p = p | a[k];
          ma = max(ma, p);
        }
    cout << ma;
  }
}
