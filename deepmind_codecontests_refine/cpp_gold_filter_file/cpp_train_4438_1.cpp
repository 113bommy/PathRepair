#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6;
string num[MAXN];
unordered_map<string, int> here;
int main() {
  int n;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  string second;
  for (int i = 1; i <= n; ++i) {
    cin >> num[i];
    for (int j = 0; j <= 9; ++j) {
      for (int k = 0; k + j <= 9; ++k) {
        second = num[i].substr(k, j);
        int v = here[second];
        if (v == 0) {
          here[second] = i;
        } else {
          if (v != i) {
            here[second] = -1;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 9; ++j) {
      bool flag = 0;
      for (int k = 0; k + j <= 9; ++k) {
        second = num[i].substr(k, j);
        if (here[second] == i) {
          cout << second << '\n';
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
  }
}
