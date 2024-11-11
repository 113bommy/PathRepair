#include <bits/stdc++.h>
using namespace std;
int hold[7];
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    for (int j = 0; j < 7; j++) {
      if (second[j] == '1') {
        hold[j]++;
      }
    }
  }
  int nax = 0;
  for (int i = 0; i < 7; i++) {
    nax = max(hold[i], nax);
  }
  cout << nax << "\n";
  return 0;
}
