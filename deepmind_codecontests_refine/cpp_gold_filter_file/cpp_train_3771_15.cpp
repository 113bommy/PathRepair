#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, mod = 1e9 + 7;
int n;
string a;
bool hi[30];
bool vs[30];
string res;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> a;
  for (int i = 0; i < n; i++) {
    bool t = false;
    for (int j = a[i] + 1; j <= 122; j++) {
      if (vs[j - 'a'] == true) {
        if (hi[j - 'a'] == true) {
          cout << "NO";
          return 0;
        }
        t = true;
      }
    }
    if (t) {
      res.push_back('1');
    } else
      res.push_back('0');
    vs[a[i] - 'a'] = true;
    hi[a[i] - 'a'] |= (res[((int)((res).size())) - 1] - '0');
  }
  cout << "YES\n";
  cout << res;
  return 0;
}
