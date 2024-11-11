#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vll = vector<long long int>;
ll freq[6];
int main() {
  int N;
  cin >> N;
  ll arr[N];
  for (int i = 0; i < N; i++) cin >> arr[i];
  vll cost(5);
  for (int i = 0; i < 5; i++) {
    cin >> cost[i];
  }
  ll currMoney = 0;
  for (int i = 0; i < N; i++) {
    currMoney += arr[i];
    auto idx = upper_bound(cost.begin(), cost.end(), currMoney) - cost.begin();
    while (idx != 0) {
      freq[idx - 1] += currMoney / cost[idx - 1];
      currMoney -= (currMoney / cost[idx - 1]) * cost[idx - 1];
      idx = upper_bound(cost.begin(), cost.end(), currMoney) - cost.begin();
    }
  }
  for (int i = 0; i < 5; i++) cout << freq[i] << " ";
  cout << "\n";
  cout << currMoney << "\n";
  return 0;
}
