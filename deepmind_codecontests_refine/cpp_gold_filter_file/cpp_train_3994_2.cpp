#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, numbers[100005] = {0}, l = 1, r = 0, found = 0, x, n, k, p = 0;
  cin >> n >> k;
  vector<int> init;
  for (i = 0; i < n; i++) {
    cin >> x;
    r++;
    init.push_back(x);
    numbers[x - 1]++;
    if (numbers[x - 1] == 1) found++;
    while (numbers[init[p] - 1] > 1) {
      l++;
      numbers[init[p] - 1]--;
      p++;
    }
    if (found == k) break;
  }
  if (found == k)
    cout << l << " " << r << endl;
  else
    cout << "-1 -1" << endl;
  return 0;
}
