#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ed(n - 1, 0);
  for (int i = 0; i < n - 1; i++) cin >> ed[i], ed[i]--;
  vector<int> nd(n, 0);
  cout << ed[0] + 1 << endl;
  int cur = n - 1;
  for (int i = 0; i < n - 1; i++) {
    nd[ed[i]]++;
    while (nd[cur]) cur--;
    if (i == n - 2 || nd[ed[i + 1]]) {
      nd[cur]++;
      cout << ed[i] + 1 << " " << cur + 1 << endl;
    } else
      cout << ed[i + 1] + 1 << " " << ed[i] + 1 << endl;
  }
  return 0;
}
