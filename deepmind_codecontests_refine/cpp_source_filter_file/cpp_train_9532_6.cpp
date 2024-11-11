#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 300010;
long long c;
int n;
map<int, int, greater<int> > v;
int main() {
  cin >> c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int(x);
    cin >> x;
    v[x]++;
  }
  for (int i = 1; i < c; i++) {
    v[i]++;
    int a = c, next = c;
    auto it = v.begin();
    while (a > 0) {
      it = v.lower_bound(next);
      if (it == v.end()) {
        break;
      } else {
        a -= min(it->second, a / (it->first)) * it->first;
        next = min(a, it->first - 1);
      }
    }
    if (a > 0) {
      cout << i << endl;
      return 0;
    }
    v[i]--;
    if (v[i] == 0) v.erase(i);
  }
  cout << "Greedy is good." << endl;
}
