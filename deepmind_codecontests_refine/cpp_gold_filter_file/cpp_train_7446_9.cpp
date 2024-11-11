#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 500100;
vector<int> tLR;
vector<int> tRL;
int main(void) {
  int n, a, b, T;
  scanf("%d %d %d %d", &n, &a, &b, &T);
  string str;
  cin >> str;
  tLR.resize(N);
  tRL.resize(N);
  for (int i = 0; i < N; i++) tLR[i] = tRL[i] = INT_MAX;
  tRL[0] = 0;
  tLR[0] = str[0] == 'w' ? (b + 1) : 1;
  for (int k = 1; k < n; k++) {
    int i = k;
    tLR[i] = tLR[i - 1] + a;
    if (str[k] == 'w')
      tLR[i] += (b + 1);
    else
      tLR[i]++;
    tRL[k] = tRL[k - 1] + a;
    if (str[n - k] == 'w')
      tRL[k] += (b + 1);
    else
      tRL[k]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int time = T - tLR[i];
    if (time < 0) break;
    int x = lower_bound(tRL.begin(), tRL.end(), time + 1 - (i * a)) -
            tRL.begin() - 1;
    if (i == 0 and x == n - 1) {
      ans = n;
      break;
    } else if (x >= 0)
      ans = max(ans, i + x + 1);
    else
      ans = max(ans, i + 1);
  }
  if (ans == n) {
    cout << n << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int time = T - tRL[i] - tLR[0];
    if (time < 0) break;
    int x = lower_bound(tLR.begin(), tLR.end(), time + 1 - (i * a) + tLR[0]) -
            tLR.begin() - 1;
    if (x >= 0)
      ans = max(ans, i + x + 1);
    else
      ans = max(ans, i);
  }
  cout << ans << endl;
  return 0;
}
