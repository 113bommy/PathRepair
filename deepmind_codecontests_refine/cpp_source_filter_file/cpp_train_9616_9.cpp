#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans, even = 0;
  int last_even = 0, last_odd = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ans;
    if (ans % 2 == 0) {
      even++;
      last_even = i;
    } else if (ans % 2 == 1) {
      even--;
      last_odd = i;
    }
  }
  if (even > 0)
    cout << last_odd << endl;
  else
    cout << last_even << endl;
  return 0;
}
