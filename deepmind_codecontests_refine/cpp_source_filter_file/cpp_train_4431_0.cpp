#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int c[n + 1];
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  int id[k + 1];
  for (int i = 1; i <= k; i++) {
    cin >> id[i];
  }
  long long pre[k + 1];
  pre[0] = 0;
  for (int i = 1; i <= k; i++) pre[i] = c[i] + pre[i - 1];
  long long tot = 0;
  bool v[n + 1];
  for (int i = 1; i <= n; i++) v[i] = false;
  for (int i = 1; i <= k; i++) {
    v[id[i]] = true;
    tot += (sum - c[id[i]]) * c[id[i]];
    tot -= pre[i - 1] * c[id[i]];
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1 && !v[i]) {
      if (!v[n]) tot += c[i] * c[n];
      if (i + 1 <= n && !v[i + 1]) tot += c[i] * c[i + 1];
      v[i] = true;
    } else {
      if (!v[i]) {
        if (!v[i - 1]) tot += c[i] * c[i - 1];
        if (i + 1 <= n && !v[i + 1]) tot += c[i] * c[i + 1];
        v[i] = true;
      }
    }
  }
  cout << tot << endl;
}
