#include <bits/stdc++.h>
using namespace std;
template <class T>
T chmin(T& a, T& b) {
  if (a > b) return a;
}
template <class T>
T chmax(T& a, T& b) {
  if (a < b) return b;
}
const long long INF = 1e18;
const int MOD = 3;
const int N = 1e5 + 3;
vector<long long> adj[N];
long long a, c, x, y;
map<long long, long long> gm;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k >= (n * (n - 1)) / 2)
    cout << "no solution";
  else {
    for (int i = 0; i < n; i++) {
      cout << 0 << " " << i + 1 << "\n";
    }
  }
}
