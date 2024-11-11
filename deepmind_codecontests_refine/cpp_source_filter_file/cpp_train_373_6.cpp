#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, x;
char s[3];
int main() {
  cin >> n;
  while (n--) {
    cin >> s;
    if (s[0] == 'a') {
      cin >> x;
      v.insert(lower_bound(v.begin(), v.end(), x), x);
    }
    if (s[0] == 'd') {
      cin >> x;
      v.erase(lower_bound(v.begin(), v.end(), x));
    }
    if (s[0] == 's') {
      int ans = 0;
      for (int i = 2; i < v.size(); i += 5) {
        ans += v[i];
      }
      cout << ans << endl;
    }
  }
  return 0;
}
