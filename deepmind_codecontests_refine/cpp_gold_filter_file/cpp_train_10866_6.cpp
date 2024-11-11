#include <bits/stdc++.h>
using namespace std;
long long inc[100001];
long long decr[100001];
vector<long long> v1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      long long num;
      cin >> num;
      v1.push_back(num);
    }
    for (long long i = v1.size() - 1; i >= 0; i--) {
      if (i == v1.size() - 1) {
        inc[i] = i;
        decr[i] = i;
        continue;
      }
      if (v1[i] <= v1[i + 1]) {
        inc[i] = inc[i + 1];
      } else {
        inc[i] = i;
      }
      if (v1[i] >= v1[i + 1]) {
        decr[i] = decr[i + 1];
      } else {
        decr[i] = i;
      }
    }
    for (long long i = 0; i < m; i++) {
      long long u, v;
      cin >> u >> v;
      if (decr[inc[u - 1]] >= v - 1) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
  return 0;
}
