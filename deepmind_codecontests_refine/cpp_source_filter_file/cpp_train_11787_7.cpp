#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int n, inp;
  cin >> n;
  vector<int> num(n + 5);
  for (int i = 0; i < n; i++) {
    cin >> inp;
    num[inp]++;
  }
  vector<int> mn(num), act(n + 5, 0);
  int mncnt = 0;
  for (int i = 1; i < n + 5; i++) {
    if (mn[i] != 0) {
      if (num[i] < mn[i])
        mncnt++;
      else if (mn[i - 1] != 0)
        continue;
      else
        mn[i + 1] += num[i];
    }
  }
  int mxcnt = 0;
  for (int i = 1; i < n + 5; i++) {
    if (num[i] != 0) {
      if (act[i - 1] == 0 && num[i]) {
        mxcnt++;
        num[i]--;
      }
      if (act[i] == 0 && num[i]) {
        mxcnt++;
        act[i]++;
        num[i]--;
      }
      if (act[i + 1] == 0 && num[i]) {
        mxcnt++;
        act[i + 1]++;
        num[i]--;
      }
    }
  }
  cout << mncnt << ' ' << mxcnt << '\n';
  return 0;
}
