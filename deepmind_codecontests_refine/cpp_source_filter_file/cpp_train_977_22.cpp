#include <bits/stdc++.h>
using namespace std;
int BIT[100000];
int ar[100000];
void update(int idx, int val) {
  int mx = val;
  int i;
  for (i = idx; i <= 99999; i = i + (i & -i)) {
    mx = max(mx, BIT[i]);
    BIT[i] = mx;
  }
}
int query(int idx) {
  int ans = 0;
  ;
  while (idx > 0) {
    ans = max(ans, BIT[idx]);
    idx = idx - (idx & -idx);
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    update(ar[i], query(ar[i] - 1) + 1);
  }
  int t = 0;
  for (int i = 1; i <= n; i++) t = max(t, BIT[i]);
  cout << t << endl;
  return 0;
}
