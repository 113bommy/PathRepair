#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
vector<long long> adj;
void doit(long long n) {
  long long k = 0;
  adj.clear();
  for (long long i = 0; k <= n; i++) {
    long long x = 0, y = INF;
    while (x <= y) {
      long long mid = (x + y) >> 1;
      if (n / (2 * mid + 1) == mid + k) {
        if (n % (2 * mid + 1) == 0) {
          if (k == 0)
            adj.push_back(2 * mid + 1);
          else
            adj.push_back((2 * mid + 1) * (1ll << (i - 1)) * 2);
        }
        break;
      } else if (n / (2 * mid + 1) < mid + k)
        y = mid - 1;
      else
        x = mid + 1;
    }
    k += (1ll << i);
  }
}
int main() {
  long long n;
  while (cin >> n) {
    doit(n);
    sort(adj.begin(), adj.end());
    if (adj.size() == 0)
      puts("-1");
    else {
      for (int i = 0; i < adj.size(); i++) cout << adj[i] << endl;
    }
  }
  return 0;
}
