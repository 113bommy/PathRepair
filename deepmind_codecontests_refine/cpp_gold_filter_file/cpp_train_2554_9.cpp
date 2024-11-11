#include <bits/stdc++.h>
using namespace std;
vector<long long int> coins;
long long int n, k;
long long int rich, poor;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    coins.push_back(x);
  }
  sort(coins.begin(), coins.end());
  reverse(coins.begin(), coins.end());
  long long avg = 0, total = 0;
  for (auto x : coins) total += x;
  avg = total / n;
  int aidx = 0;
  for (int i = 0; i < n; i++)
    if (coins[i] <= avg) {
      aidx = i;
      break;
    }
  long long rem = k;
  int ridx = 0;
  for (int i = 0; i < n - 1; i++) {
    long long add = (i + 1) * (coins[i] - coins[i + 1]);
    if (add <= rem) {
      rem -= add;
    } else {
      ridx = i;
      break;
    }
  }
  rich = coins[ridx] - (rem / (ridx + 1));
  int pidx = n - 1;
  rem = k;
  for (int i = n - 1; i > 0; i--) {
    long long add = (n - i) * (coins[i - 1] - coins[i]);
    if (rem < add) {
      pidx = i;
      break;
    } else {
      rem -= add;
    }
  }
  poor = coins[pidx] + (rem / (n - pidx));
  if (rich <= avg) {
    if (total == (n * avg))
      cout << 0 << endl;
    else
      cout << 1 << endl;
  } else {
    cout << rich - poor << endl;
  }
  return 0;
}
