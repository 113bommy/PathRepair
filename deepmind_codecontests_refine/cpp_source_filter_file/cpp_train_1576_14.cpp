#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100001;
const int M = 20;
const int MOD = 1000000007;
const int inf = 1234567890;
const long long INF = 1122334455667788990;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int tc = 1, cs = 0;
  while (tc--) {
    double n, r, cosine, radius;
    cin >> n >> r;
    cosine = (2 * acos(-1)) / n;
    double x = sqrt((1 - cosine) / 2);
    radius = (r * x) / (1 - x);
    cout << fixed << setprecision(10);
    cout << radius << '\n';
  }
}
