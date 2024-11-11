#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> ins, ans;
  long long i, j, n;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    ins.push_back(j);
  }
  long long ekhon, ekhon1;
  for (i = 31; i >= 0; i--) {
    ekhon = 1 << (i + 1);
    ekhon--;
    ans.clear();
    ekhon1 = 1 << i;
    for (j = 0; j < n; j++)
      if (ins[j] & ekhon1) {
        ans.push_back(ins[j]);
        ekhon = ekhon & ins[j];
      }
    if (ans.size() && (ekhon1 % ekhon)) break;
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
