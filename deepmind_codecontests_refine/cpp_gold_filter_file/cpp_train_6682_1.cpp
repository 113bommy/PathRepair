#include <bits/stdc++.h>
const long long mod9 = 1e9 + 7;
const long long maxsize = 2e9 + 1;
const long long mod2 = 1073741824;
using namespace std;
vector<long long> lucky_number;
void lucky(string m) {
  if (m.length() > 9) return;
  lucky_number.push_back(stoi(m));
  lucky(m + '4');
  lucky(m + '7');
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  lucky("4");
  lucky("7");
  lucky_number.push_back(4444444444);
  sort(lucky_number.begin(), lucky_number.end());
  long long l, r;
  cin >> l >> r;
  long long sum = 0;
  long long current = l;
  long long current_lb =
      *(lower_bound(lucky_number.begin(), lucky_number.end(), current));
  while (current_lb <= r) {
    sum += (current_lb - current + 1) * current_lb;
    if (current_lb == r) {
      current = r + 1;
      break;
    }
    current = current_lb + 1;
    current_lb =
        *(lower_bound(lucky_number.begin(), lucky_number.end(), current));
  }
  sum += (r - current + 1) * current_lb;
  cout << sum;
  return 0;
}
