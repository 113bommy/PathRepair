#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
long long int ara[] = {1, 5, 10, 50}, ans[100];
void pre() {
  for (int i = 0; i < 4; i++) mp[ara[i]] = 1;
  ans[1] = mp.size();
  for (int i = 2; i <= 50; i++) {
    map<int, int> tmp;
    for (auto x : mp) {
      for (int j = 0; j < 4; j++) {
        tmp[x.first + ara[j]] = 1;
      }
    }
    mp = tmp;
    ans[i] = mp.size();
  }
}
int main() {
  pre();
  int n;
  cin >> n;
  if (n <= 50)
    cout << ans[n] << '\n';
  else
    cout << ans[50] + (n - 50) * 49 << '\n';
  return 0;
}
