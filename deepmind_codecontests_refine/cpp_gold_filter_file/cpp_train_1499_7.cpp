#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t startTime = clock();
  long long T = 1;
  while (T--) {
    long long n;
    cin >> n;
    map<string, long long> m;
    string winner;
    long long mx = LLONG_MIN;
    string x[n];
    long long v[n];
    for (long long i = 0; i < n; i++) {
      cin >> x[i] >> v[i];
      m[x[i]] += v[i];
    }
    set<string> second;
    for (auto i : m) {
      if (i.second > mx) {
        mx = i.second;
        winner = i.first;
        second.clear();
        second.insert(i.first);
      } else if (i.second == mx) {
        second.insert(i.first);
      }
    }
    map<string, long long> g;
    for (long long i = 0; i < n; i++) {
      g[x[i]] += v[i];
      if (g[x[i]] >= mx && second.find(x[i]) != second.end()) {
        return cout << x[i], 0;
      }
    }
  }
}
