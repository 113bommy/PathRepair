#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int solve() {
  int m, s;
  cin >> m >> s;
  if (s == 0) {
    if (m != 1) {
      cout << "-1 -1" << endl;
    } else if (m == 1) {
      cout << "0 0" << endl;
    }
  } else {
    string mini = "", maxi = "";
    for (long long i = 0; i < m; i++) {
      int k = min(9, s);
      maxi.push_back('0' + k);
      s -= k;
    }
    if (s > 0) {
      cout << "-1 -1";
      return 0;
    }
    mini = maxi;
    reverse(mini.begin(), mini.end());
    int j = 0;
    while (j == '0') {
      j++;
    }
    mini[j]--;
    mini[0]++;
    cout << mini << " " << maxi;
  }
}
int main() { solve(); }
