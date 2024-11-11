#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
bool st[N];
string s;
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(st, 0, sizeof(st));
    cin >> s;
    long long res = 0;
    int l = s.size();
    int cur = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '-') {
        cur--;
        if (cur < 0 && !st[-cur]) {
          res += i + 1;
          st[-cur] = true;
        }
      } else
        cur++;
    }
    res += l;
    cout << res << endl;
  }
  return 0;
}
