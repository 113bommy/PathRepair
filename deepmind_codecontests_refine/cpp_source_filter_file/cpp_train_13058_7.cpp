#include <bits/stdc++.h>
using namespace std;
void c_p_c() {}
int main(int argc, char const *argv[]) {
  c_p_c();
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, t, c;
  cin >> n >> t >> c;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0, ans = 0, div = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] <= t) {
      cnt++;
    } else {
      if (cnt >= c) {
        ans += (cnt - c) + 1;
      }
      cnt = 0;
    }
  }
  if (cnt >= 0) ans += (cnt - c) + 1;
  cout << ans << endl;
}
