#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pcc = pair<char, char>;
using pdd = pair<double, double>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vc = vector<char>;
using vd = vector<double>;
int main(int argc, char* argv[]) {
  int t, i, j, ara[200100];
  vector<pii> v;
  scanf("%d%*c", &(t));
  while (t--) {
    int n, x;
    scanf("%d%*c", &(n));
    for (i = 0; i < n; i++) {
      scanf("%d%*c", &(ara[i]));
    }
    for (i = 0; i < n - 1; i++) {
      if (abs(ara[i + 1] - ara[i]) > 1) {
        printf("YES\n%d %d\n", i + 1, i + 2);
        break;
      }
    }
    if (i == n - 1) printf("NO\n");
  }
  return 0;
}
