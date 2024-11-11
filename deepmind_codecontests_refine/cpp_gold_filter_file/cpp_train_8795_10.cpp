#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, ans = 0;
  cin >> n >> l;
  n--;
  int cands[n];
  for (int i = 0; i < n; i++) cin >> cands[i];
  sort(cands, cands + n);
  while (l <= cands[n - 1]) {
    if (cands[n - 1] == *max_element(cands, cands + n)) {
      cands[n - 1] -= 1;
      ans++;
      l++;
    }
    sort(cands, cands + n);
  }
  cout << ans;
}
