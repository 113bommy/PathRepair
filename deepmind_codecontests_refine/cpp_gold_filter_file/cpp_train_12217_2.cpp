#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  a--;
  string l = to_string(a);
  string r = to_string(b);
  long long int ans1;
  if (l.length() == 1) {
    ans1 = a;
  } else {
    if (l[0] <= l[(l.length() - 1)]) {
      ans1 = (a / 10) + 9;
    } else {
      ans1 = (a / 10) + 8;
    }
  }
  long long int ans2;
  if (r.length() == 1) {
    ans2 = b;
  } else {
    if (r[0] <= r[(r.length() - 1)]) {
      ans2 = (b / 10) + 9;
    } else {
      ans2 = (b / 10) + 8;
    }
  }
  cout << ans2 - ans1 << endl;
  return 0;
}
