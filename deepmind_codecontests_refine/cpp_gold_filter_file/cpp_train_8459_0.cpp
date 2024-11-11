#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  function<int(char, int)> ask = [&](char type, int val) {
    cout << type << " " << val << endl;
    int res;
    cin >> res;
    return res;
  };
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;
  for (int p = 2; p * p <= n; p++)
    if (prime[p] == true)
      for (int k = p * p; k <= n; k += p) prime[k] = false;
  int threshold = 100;
  vector<int> block;
  int x = 1;
  int cnt = n;
  function<void()> solve = [&]() {
    int correct = ask('A', 1);
    if (cnt != correct) {
      cnt = correct;
      for (int q : block) {
        while (1LL * x * q <= n && ask('A', x * q) > 0) x *= q;
      }
    }
    block.clear();
  };
  for (int p = 2; p <= n; p++)
    if (prime[p] == true) {
      cnt -= ask('B', p);
      block.push_back(p);
      if ((int)block.size() > threshold) solve();
    }
  if (block.empty() == false) solve();
  cout << "C " << x << endl;
  return 0;
}
