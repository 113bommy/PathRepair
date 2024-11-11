#include <bits/stdc++.h>
using namespace std;
int n;
long long d[100010];
long long c[100010];
vector<pair<long long, long long> > V;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> c[i];
    V.push_back(make_pair(d[i], c[i]));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  for (int p = V[0].first + 1;; p++) {
    long long r = 1;
    int ok = 1;
    int prev = p;
    for (int i = 0; i < n; i++) {
      while (prev != V[i].first) {
        r *= 4;
        if (r > (1LL << 50)) {
          cout << p << endl;
          return 0;
        }
        prev--;
      }
      if (r < V[i].second) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << p << endl;
      break;
    }
  }
  return 0;
}
