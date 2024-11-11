#include <bits/stdc++.h>
using namespace std;
int n;
int sg[100003];
int best = -1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 3; i <= n; i++) {
    unordered_set<int> nimbers;
    for (int j = 2; j * j <= 2 * i; j++)
      if ((2 * n) % j == 0 && (2 * n / j + 1 - j) % 2 == 0) {
        int first = (2 * n / j + 1 - j) / 2;
        int curr_xor = 0;
        for (int k = first; k <= first + j - 1; k++) curr_xor ^= sg[k];
        nimbers.insert(curr_xor);
        if (i == n && curr_xor == 0 && best == -1) best = j;
      }
    while (nimbers.find(sg[i]) != nimbers.end()) sg[i]++;
  }
  if (sg[n] == 0)
    cout << -1 << '\n';
  else
    cout << best << '\n';
}
