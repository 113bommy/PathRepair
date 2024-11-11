#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> vc(n);
  vector<int> vc1(k);
  for (int i = 0; i < n; i++) {
    cin >> vc[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> vc1[i];
  }
  sort(vc1.rbegin(), vc1.rend());
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (vc[i] == 0) {
      vc[i] = vc1[j];
      j++;
    }
  }
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (vc[i] < vc[i + 1]) {
      continue;
    } else {
      flag = 1;
    }
  }
  if (flag == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
int main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
