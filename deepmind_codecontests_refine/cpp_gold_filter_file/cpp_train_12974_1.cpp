#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, a;
  cin >> n >> s;
  vector<int> v;
  while (n--) {
    cin >> a;
    v.push_back(a);
  }
  int sum = 0;
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    ans++;
    sum = sum + 86400 - v[i];
    if (sum >= s) {
      cout << ans << endl;
      break;
    }
  }
}
