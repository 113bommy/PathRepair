#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> mp;
vector<int> fact;
int calc(int rem) {
  if (rem == 1) return 0;
  if (mp.find(rem) != mp.end()) return mp[rem];
  int best = 0;
  for (int i = 0; i < fact.size(); ++i)
    if (rem % fact[i] == 0)
      best = max(best, calc(rem / fact[i]) + rem / fact[i]);
    else if (rem > fact[i])
      break;
  return mp[rem] = best;
}
int main() {
  cin >> n;
  int g = n;
  int i = 2;
  while (i * i <= g) {
    if (g % i == 0) fact.push_back(i);
    while (g % i == 0) g /= i;
    ++i;
  }
  if (g != 1) fact.push_back(g);
  cout << calc(n) + n << endl;
}
