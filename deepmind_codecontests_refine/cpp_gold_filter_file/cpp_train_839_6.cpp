#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 100;
long long res[MAX];
void solve() {
  long long a, b;
  cin >> a;
  vector<pair<long long, long long> > x(a);
  vector<long long> f;
  for (int i = 0; i < a; ++i) {
    cin >> x[i].first >> x[i].second;
    f.push_back(x[i].first);
    f.push_back(x[i].second);
  }
  sort(x.begin(), x.end());
  sort(f.begin(), f.end());
  long long cur = 0;
  long long last = 0;
  multiset<long long> g;
  int j = 0;
  for (int i = 0; i < f.size(); ++i) {
    cur = f[i];
    res[g.size()] += cur - last;
    while (j < a && x[j].first == cur) {
      g.insert(x[j].second);
      j++;
    }
    res[g.size()]++;
    g.erase(cur);
    last = cur + 1;
  }
  for (int i = 1; i <= a; ++i) {
    cout << res[i] << ' ';
  }
  cout << endl;
}
int main() { solve(); }
