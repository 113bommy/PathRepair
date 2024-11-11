#include <bits/stdc++.h>
using namespace std;
const int maxT = 1000 * 1000 * 10 + 1000;
int ready[3][maxT];
int current[4];
int n[3];
int t[3];
int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k >> n[0] >> n[1] >> n[2] >> t[0] >> t[1] >> t[2];
  int tm = -1;
  current[0] = k;
  while (current[3] < k) {
    tm++;
    for (int i = (0); i < (3); i++) current[i + 1] += ready[i][tm];
    for (int i = (0); i < (3); i++) n[i] += ready[i][tm];
    for (int i = (0); i < (3); i++) {
      int x = min(n[i], current[i]);
      current[i] -= x;
      n[i] -= x;
      ready[i][tm + t[i]] += x;
    }
  }
  cout << tm << endl;
  return 0;
}
