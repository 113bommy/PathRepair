#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 35;
const long long N = 1e7 + 35;
const long long mod = 3e18;
const double eps = 1e-6;
string a[MAX];
map<string, int> mm;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 1; j < 9; j++) {
      for (int k = 0; k + j < 10; k++) {
        string s = a[i].substr(k, j);
        if (mm[s] == 0)
          mm[s] = i + 1;
        else if (mm[s] != i + 1)
          mm[s] = -1;
      }
    }
  }
  string s;
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 1; j < 9; j++) {
      for (int k = 0; k + j < 10; k++) {
        s = a[i].substr(k, j);
        if (mm[s] == i + 1) {
          ok = 1;
          break;
        }
      }
      if (ok) break;
    }
    cout << s << "\n";
  }
}
