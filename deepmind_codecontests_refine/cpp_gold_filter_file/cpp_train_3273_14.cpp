#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x[n], y[n], cnt[100005] = {0}, b[n][2];
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    cnt[x[i]]++;
  }
  for (int i = 0; i < n; i++) {
    b[i][0] = n - 1;
    b[i][0] += cnt[y[i]];
    b[i][1] = n - 1 - cnt[y[i]];
  }
  for (int i = 0; i < n; i++) cout << b[i][0] << " " << b[i][1] << endl;
}
