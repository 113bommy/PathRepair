#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
map<int, int> ma1, ma2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r;
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  sort(a + l, a + r + 1);
  sort(b + l, b + r + 1);
  int flag = 1;
  for (int i = l; i <= r; i++) {
    if (a[i] != b[i]) {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "TRUTH";
  } else {
    cout << "LIE";
  }
  return 0;
}
