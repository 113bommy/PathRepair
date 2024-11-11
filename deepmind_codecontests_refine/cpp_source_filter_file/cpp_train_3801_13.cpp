#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
long long MOD = 998244353;
int main() {
  long long x;
  cin >> x;
  long long m = 1000000;
  vector<pair<long long, long long> > sets;
  for (long long i = 1; i < 200005; i++) {
    long long s = 6 * x + i * i * i - i;
    m = (3 * i + 3) * i;
    if (!(s % m) && i <= s / m) {
      sets.push_back({i, s / m});
      if (s / m != i) sets.push_back({s / m, i});
    }
  }
  sort(sets.begin(), sets.end());
  cout << sets.size() << endl;
  for (int i = 0; i < sets.size(); i++) {
    cout << sets[i].first << " " << sets[i].second << endl;
  }
}
