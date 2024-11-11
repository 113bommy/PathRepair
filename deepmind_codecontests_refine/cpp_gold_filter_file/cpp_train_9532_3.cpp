#include <bits/stdc++.h>
using namespace std;
int c, n;
int coins[250000];
map<int, int> coinsWithAmount;
bool works(int x) {
  int sum = 0;
  bool summed = false;
  int ultimaMoneda = 250000 + 1;
  while (sum < c &&
         coinsWithAmount.begin()->first <= min(c - sum, ultimaMoneda - 1)) {
    auto it = --coinsWithAmount.lower_bound(min(c - sum + 1, ultimaMoneda));
    if (!summed && x >= it->first && c - sum >= x) {
      sum += x;
      summed = true;
    } else {
      int times = min((c - sum) / it->first, it->second);
      sum += times * it->first;
      ultimaMoneda = it->first;
    }
  }
  return sum != c;
}
int calculate() {
  for (int i = 1; i <= c; i++)
    if (works(i)) return i;
  return 0;
}
int main() {
  cin >> c >> n;
  for (int i = (int)(0); i < (int)(n); i++) {
    int temp;
    cin >> temp;
    coins[temp]++;
  }
  for (int i = (int)(0); i < (int)(250000); i++) {
    if (coins[i] != 0) {
      coinsWithAmount[i] = coins[i];
    }
  }
  int r = calculate();
  if (r == 0)
    cout << "Greed is good" << endl;
  else
    cout << r << endl;
  return 0;
}
