#include <bits/stdc++.h>
using namespace std;
const long long modulo = 1000000007;
const int inf = 0x3f3f3f3f;
const long long ll_inf = 0x3f3f3f3f3f3f3f3f;
int n, k;
vector<int> powers, coins;
map<int, int> power_to_coins;
map<int, int> number_to_power;
map<int, int> power_to_best_coins;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int power;
    cin >> power;
    powers.push_back(power);
    number_to_power[i] = power;
  }
  for (int i = 0; i < n; i++) {
    int coin;
    cin >> coin;
    coins.push_back(coin);
    power_to_coins[number_to_power[i]] = coin;
  }
  priority_queue<int> sorted_coins;
  long long sorted_coins_sum = 0;
  sort(powers.begin(), powers.end());
  for (int i = 0; i < n; i++) {
    power_to_best_coins[powers.at(i)] =
        power_to_coins[powers.at(i)] + sorted_coins_sum;
    sorted_coins.push(-power_to_coins[powers.at(i)]);
    sorted_coins_sum += power_to_coins[powers.at(i)];
    if (sorted_coins.size() > k) {
      sorted_coins_sum += sorted_coins.top();
      sorted_coins.pop();
    }
  }
  for (int i = 0; i < n; i++) {
    cout << power_to_best_coins[number_to_power[i]] << " ";
    ;
  }
  cout << endl;
}
