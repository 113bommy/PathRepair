#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using i3 = pair<int, ii>;
using li = pair<ll, int>;
using lii = pair<ll, ii>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<ii>;
using vpll = vector<pll>;
using vi3 = vector<i3>;
using vlii = vector<lii>;
const int N = 1;
const ll INF = 1e17 + 7;
const double eps = 1e-9, PI = acos(-1);
int n;
void solve(int testCase) {
  scanf("%d", &n);
  vi v;
  for (int i = 1; i * i <= n; i++) {
    v.push_back(i);
    if (n / i != i) {
      v.push_back(n / i);
    }
  }
  sort(v.begin(), v.end());
  printf("%d\n", v.size());
  printf("0");
  for (int V : v) printf(" %d", V);
  printf("\n");
}
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int testCase = 1; testCase <= t; testCase++) {
    solve(testCase);
  }
  return 0;
}
