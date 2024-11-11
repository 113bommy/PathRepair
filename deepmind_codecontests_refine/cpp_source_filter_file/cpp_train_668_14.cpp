#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.size();
  int a[2];
  int b[2];
  a[0] = a[1] = 0;
  b[0] = b[1] = 0;
  long long ans_odd = 0LL;
  long long ans_even = 0LL;
  for (int i = 0; i < l; i++) {
    ans_odd++;
    if (s[i] == 'a') {
      ans_even += a[i % 2];
      ans_odd += a[1 - i % 2];
    } else {
      ans_even += b[1 - i % 2];
      ans_odd += b[i % 2];
    }
    a[i % 2] += (s[i] == 'a');
    b[i % 2] += (s[i] == 'b');
  }
  cout << ans_even << " " << ans_odd << endl;
  return 0;
}
