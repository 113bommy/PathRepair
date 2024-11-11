#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int arr[N], BIT[N], lucky[N];
void updt(int idx, int x) {
  while (idx < N) BIT[idx] += x, idx += (idx & -idx);
}
int qry(int idx) {
  int ret = 0;
  while (idx > 0) ret += BIT[idx], idx -= (idx & -idx);
  return ret;
}
void EASY(int now) {
  lucky[now] = 1;
  if (now < 1e5) {
    EASY(now * 10 + 4);
    EASY(now * 10 + 7);
  }
}
int main() {
  EASY(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    if (lucky[arr[i]]) updt(i, 1);
  }
  while (m--) {
    string s;
    cin >> s;
    int l, r;
    cin >> l >> r;
    if (s[0] == 'a') {
      int d;
      cin >> d;
      for (int i = l; i <= r; i++) {
        if (lucky[arr[i]]) updt(i, -1);
        arr[i] += d;
        if (lucky[arr[i]]) updt(i, 1);
      }
    } else
      cout << qry(r) - qry(l - 1) << "\n";
  }
  return 0;
}
