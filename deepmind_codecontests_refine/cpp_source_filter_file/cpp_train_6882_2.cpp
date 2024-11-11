#include <bits/stdc++.h>
using namespace std;
long long int ans = 0;
int sd(long long int rem) {
  int sum = 0;
  while (rem) {
    sum += rem % 10;
    rem /= 10;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int pos[13] = {0,           9,         99,         999,
                           9999,        99999,     999999,     9999999,
                           99999999,    999999999, 9999999999, 99999999999,
                           999999999999};
  long long int n;
  cin >> n;
  if (n > pos[12]) {
    cout << pos[12] + sd(n - pos[12]) << "\n";
    return 0;
  }
  long long int rem;
  for (int i = 0; i < 12; i++) {
    if (n >= pos[i] && n < pos[i + 1]) {
      rem = n - pos[i];
      ans += 9 * (i);
      break;
    }
  }
  ans += sd(rem);
  cout << ans << "\n";
  return 0;
}
