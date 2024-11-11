#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> divisorsCnt(3001 + 1);
  for (int i = 2; i <= 3001; i++)
    if (!divisorsCnt[i])
      for (int j = 2 * i; j <= 3001; j += i) divisorsCnt[j]++;
  vector<int> ans(3001 + 1);
  for (int i = 1; i <= 3001; i++) ans[i] = ans[i - 1] + (divisorsCnt[i] == 2);
  int n;
  cin >> n;
  cout << ans[n] << endl;
  return 0;
}
