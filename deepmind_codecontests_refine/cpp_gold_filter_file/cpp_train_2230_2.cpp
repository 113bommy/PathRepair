#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000;
const long long MOD = 1000000007;
int pol[200113], dp1[200113], dp2[200113];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> pol[i];
  }
  for (int i = 1; i <= n; i++) dp1[i] = dp1[i - 1] + pol[i];
  for (int i = n; i >= 1; i--) dp2[i] = (pol[i]) ? dp2[i + 1] : dp2[i + 1] + 1;
  long long ans1 = 0, ans2 = 0;
  for (int i = n; i >= 1; i--) ans1 += (!pol[i]) ? dp1[i] : 0;
  for (int i = 1; i <= n; i++) ans2 += (pol[i]) ? dp2[i] : 0;
  cout << min(ans1, ans2);
}
