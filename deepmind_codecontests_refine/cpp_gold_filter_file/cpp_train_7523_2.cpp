#include <bits/stdc++.h>
using namespace std;
const int Max = 1e6 + 5;
int lst[Max];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> lst[i];
  map<long long, int> ma;
  long long sum = 0;
  ma[0]++;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    sum += lst[i];
    if (ma[sum]) {
      ans++;
      ma.clear();
      sum = lst[i];
      ma[sum]++;
      ma[0]++;
    } else {
      ma[sum]++;
    }
  }
  cout << ans;
}
