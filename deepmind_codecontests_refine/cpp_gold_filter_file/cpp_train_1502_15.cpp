#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  long long int req_B = 0, req_S = 0, req_C = 0;
  long long int size = s.size();
  for (long long int i = 0; i < size; i++) {
    if (s[i] == 'B') req_B++;
    if (s[i] == 'C') req_C++;
    if (s[i] == 'S') req_S++;
  }
  long long int home_B, home_S, home_C;
  cin >> home_B >> home_S >> home_C;
  long long int price_B, price_S, price_C;
  cin >> price_B >> price_S >> price_C;
  long long int our_money;
  cin >> our_money;
  long long int ans = 0;
  long long int low = 0;
  long long int high = our_money + 3 * home_B;
  while (high - low > 1) {
    long long int mid = (low + high) / 2;
    long long int money_req = our_money;
    if (mid * req_B - home_B > 0) money_req -= (mid * req_B - home_B) * price_B;
    if (mid * req_S - home_S > 0) money_req -= (mid * req_S - home_S) * price_S;
    if (mid * req_C - home_C > 0) money_req -= (mid * req_C - home_C) * price_C;
    if (money_req >= 0)
      low = mid;
    else
      high = mid;
  }
  cout << low << "\n";
  return 0;
}
