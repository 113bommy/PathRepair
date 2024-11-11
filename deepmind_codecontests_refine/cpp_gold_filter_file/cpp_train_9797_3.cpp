#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1000LL * 1000 * 1000 * 1000 * 1000 * 1000;
const int inf = 1000 * 1000 * 1000;
const long double PI = acos(-1.0);
const long long mod1 = inf + 7;
const long long mod2 = inf + 9;
const int MAXN = 2001;
const long double EPS = 1e-9;
int hp = 179;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  srand(time(NULL));
  ;
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
      cout << i << " ";
    }
    return 0;
  }
  if (k >= n - 1) {
    cout << 1 << "\n" << 1;
    return 0;
  }
  if (2 * k + 1 >= n) {
    cout << 1 << "\n" << (n + 1) / 2 << '\n';
    return 0;
  }
  if (n % (2 * k + 1) == 0) {
    cout << n / (2 * k + 1) << '\n';
    int lt = 0;
    while (lt < n) {
      cout << lt + k + 1 << ' ';
      lt += 2 * k + 1;
    }
    return 0;
  }
  if (n % (2 * k + 1) < k + 1) {
    vector<int> ans;
    int lt = 1 + k;
    for (;;) {
      ans.push_back(lt - k);
      if (n - lt < 2 * k + 1) {
        ans.push_back(lt + k + 1);
        break;
      }
      lt += 2 * k + 1;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
    ;
    return 0;
  }
  vector<int> ans;
  int lt = 2 * k + 1;
  for (;;) {
    ans.push_back(lt - k);
    if (n - lt < 2 * k + 1) {
      ans.push_back(lt + k + 1);
      break;
    }
    lt += 2 * k + 1;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  ;
}
