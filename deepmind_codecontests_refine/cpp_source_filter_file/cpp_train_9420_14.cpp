#include <bits/stdc++.h>
using namespace std;
int dis[210];
pair<int, int> pi[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> pi[i].first;
  for (int i = 0; i < n; i++) {
    cin >> pi[i].second;
    int temp = pi[i].second;
    dis[temp]++;
  }
  sort(pi, pi + n);
  int i = n - 1;
  int calc = 0;
  int ans = 10000000;
  int sum = 0;
  int left = n;
  int flag = 0;
  while (i >= 0) {
    sum = calc;
    int prev = pi[i].first;
    int c = 0;
    while (prev == pi[i].first && i >= 0) {
      c++;
      calc += pi[i].second;
      dis[pi[i].second]--;
      i--;
    }
    int left = max(0, (i + 1 - (c - 1)));
    for (int j = 1; j <= 200; j++) {
      int mini = min(left, dis[j]);
      sum += mini * j;
      left -= mini;
    }
    ans = min(sum, ans);
  }
  cout << ans << endl;
}
