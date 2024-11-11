#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vr(n);
  vector<int> sum(n);
  cin >> vr[0];
  sum[0] = vr[0];
  for (int i = 1; i < n; i++) {
    cin >> vr[i];
    vr[i] += vr[i - 1];
  }
  int s, f;
  cin >> s >> f;
  f--;
  s--;
  f--;
  int ans;
  int mx = vr[0];
  for (int i = 0; i < n; i++) {
    int sum = 0;
    int st = s - i;
    if (st >= 0) {
    } else {
      st += n;
    }
    int fn = f - i;
    if (fn >= 0) {
    } else {
      fn += n;
    }
    if (st <= fn) {
      sum += vr[fn];
      if (st != 0) sum -= vr[st - 1];
    } else {
      sum += vr[fn] + vr[n - 1];
      if (st != 0) sum -= vr[st - 1];
    }
    if (sum >= mx) {
      mx = sum;
      ans = i + 1;
    }
  }
  cout << ans << endl;
}
