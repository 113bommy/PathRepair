#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n, -1);
  int best = 0;
  for (int j = 1; j < n; j++) {
    int AmodB, BmodA;
    cout << "? " << best + 1 << " " << j + 1 << '\n';
    cout.flush();
    cin >> AmodB;
    cout << "? " << j + 1 << " " << best + 1 << '\n';
    cout.flush();
    cin >> BmodA;
    if (BmodA > AmodB) {
      arr[j] = BmodA;
      best = best;
    } else {
      arr[best] = AmodB;
      best = j;
    }
  }
  cout << "! ";
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1)
      cout << n << " ";
    else
      cout << arr[i] << " ";
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 0;
  for (int i = 0; i < t; i++) {
    solve();
  }
  return 0;
}
