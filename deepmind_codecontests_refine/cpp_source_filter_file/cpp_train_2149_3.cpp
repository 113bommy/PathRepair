#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int INF = 1000000007;
const double PI = acos(-1.0);
long long f[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  f[1] = 1;
  f[2] = 2;
  for (int i = 3; i <= N; ++i) {
    f[i] = N + f[N - 2];
  }
  cout << f[N] << endl;
  return 0;
}
