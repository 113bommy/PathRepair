#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int OO = 1000000000;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ar[107];
  for (int i = 0; i < n; i++) cin >> ar[i];
  int pos1, pos2;
  for (int i = 0; i < n; i++) {
    if (ar[i] == 1) pos1 = i;
    if (ar[i] == n) pos2 = i;
  }
  if (pos1 > pos2) swap(pos1, pos2);
  cout << max(pos2 - 1, n - pos1 - 1) << endl;
}
