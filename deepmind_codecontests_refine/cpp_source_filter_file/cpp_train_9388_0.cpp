#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f |= (ch == '-'), ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  }
  return x = f ? -x : x;
}
void solve(void) {
  int t;
  cin >> t;
  while (t--) {
    int blow_type_no, initial_head_no;
    cin >> blow_type_no >> initial_head_no;
    vector<int> decrease(blow_type_no), increase(blow_type_no);
    int highest_decrease = INT_MIN, highest_net_difference = INT_MIN;
    for (int i = 0; i < blow_type_no; i++) {
      cin >> decrease[i] >> increase[i];
      highest_decrease = max(highest_decrease, decrease[i]);
      highest_net_difference =
          max(highest_net_difference, increase[i] - decrease[i]);
    }
    int baki_thake = initial_head_no - highest_decrease;
    if (baki_thake > 0 && highest_net_difference <= 0)
      cout << -1 << "\n";
    else if (baki_thake <= 0)
      cout << 1 << "\n";
    else if (baki_thake % highest_net_difference == 0)
      cout << 1 + (baki_thake / highest_net_difference) << "\n";
    else
      cout << 2 + (baki_thake / highest_net_difference) << "\n";
  }
}
int main(void) {
  if (0) {
    int t = 100;
    for (int i = 1; i <= t; i++) solve();
  } else {
    solve();
  }
  return 0;
}
