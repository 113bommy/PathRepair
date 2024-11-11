#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int Max(long long int a, long long int b, long long int c) {
  return max(a, max(c, b));
}
void solve() {
  string st;
  cin >> st;
  int lower = 0, upper = 0, answer = 1e8;
  for (int i = 0; i < st.length(); i++) {
    if (islower(st[i])) {
      lower++;
    } else {
      upper++;
      answer = min(lower, upper);
      upper = answer;
    }
  }
  cout << answer << endl;
}
int main() {
  bool test = false;
  if (test) {
    int tt;
    cin >> tt;
    while (tt > 0) {
      solve();
      tt--;
    }
  } else {
    solve();
  }
  return 0;
}
