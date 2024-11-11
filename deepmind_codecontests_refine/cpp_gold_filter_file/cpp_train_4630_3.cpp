#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int t[n];
  for (int i = 0; i < n; i++) cin >> t[i];
  int count[3] = {0};
  for (int i = 0; i < n; i++) count[t[i] - 1]++;
  sort(count, count + 3);
  cout << count[0] << "\n";
  bool chosen[n];
  for (int i = 0; i < n; i++) chosen[i] = false;
  for (int i = 0; i < count[0]; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < n; k++) {
        if (t[k] - 1 == j && !chosen[k]) {
          cout << k + 1;
          if (j < 2) cout << " ";
          chosen[k] = true;
          break;
        }
      }
    }
    cout << "\n";
  }
  return 0;
}
