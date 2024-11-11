#include <bits/stdc++.h>
using namespace std;
int n, l, r, Ql, Qr;
vector<int> nums;
int main() {
  ios_base::sync_with_stdio(false);
  scanf("%d %d %d %d %d", &n, &l, &r, &Ql, &Qr);
  for (int i = 0; i < n; ++i) {
    int num;
    scanf("%d", &num);
    nums.push_back(num);
  }
  vector<int> com(n + 1);
  com[0] = 0;
  for (int i = 0; i < n; ++i) {
    com[i + 1] = com[i] + nums[i];
  }
  int tot = INT_MAX;
  for (int i = 0; i <= n; ++i) {
    int tmpTot = com[i] * l + (com[n] - com[i]) * r;
    if (i <= n / 2 && i * 2 != n && n != 1)
      tmpTot += (n - 2 * i - 1) * Qr;
    else if (i * 2 != n && n != 1)
      tmpTot += (i - (n - i - 1)) * Ql;
    tot = min(tot, tmpTot);
  }
  cout << tot << endl;
  return 0;
}
