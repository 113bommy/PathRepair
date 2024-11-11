#include <bits/stdc++.h>
using namespace std;
int nn[50010];
int main() {
  int n;
  cin >> n;
  long long sum = 0, ave;
  for (int i = 0; i < n; i++) {
    cin >> nn[i];
    sum += nn[i];
  }
  ave = sum / n;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += fabs(nn[i] - ave);
    nn[i + 1] -= ave - nn[i];
  }
  cout << ans;
  return 0;
}
