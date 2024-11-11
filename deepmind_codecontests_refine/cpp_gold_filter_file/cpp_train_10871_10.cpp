#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> len(n);
  for (int i = 0; i < n; i++) {
    cin >> len[i];
  }
  sort(len.begin(), len.end());
  int step = 0;
  int old_nb = 100000;
  int old_start;
  while (1) {
    int mx = 0;
    int mn = 0;
    vector<int> delta(n, 0);
    for (int i = 1; i < n; i++) {
      delta[i] = (len[0] + i * step) - len[i];
      if (delta[i] > mx) mx = delta[i];
      if (delta[i] < mn) mn = delta[i];
    }
    int nb = (mx - mn + 1) / 2;
    if (nb > old_nb) {
      cout << old_nb << endl;
      cout << old_start << " " << --step << endl;
      break;
    }
    old_start = len[0] - (mx + mn) / 2;
    old_nb = nb;
    step++;
  }
  return 0;
}
