#include <bits/stdc++.h>
using namespace std;
const long double Pi = 3.141592653;
const long long mod = 1e9 + 7;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first < b.first) || (a.first == b.first && a.second > b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> s;
    s.insert(0);
    s.insert(1);
    for (long long i = 1; i <= sqrt(n); i++) {
      s.insert(n / i);
      s.insert(i);
    }
    cout << s.size() << endl;
    for (auto &i : s) cout << i << " ";
    cout << endl;
  }
}
