#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> pr[200001];
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    pr[i].first = x;
    pr[i].second = i;
  }
  sort(pr + 1, pr + n + 1);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(pr[i].second - pr[i + 1].second);
  }
  cout << endl;
  cout << ans << endl;
}
