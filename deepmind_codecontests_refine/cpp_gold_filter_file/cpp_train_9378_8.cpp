#include <bits/stdc++.h>
using namespace std;
long long n, f, a[101010], ans;
set<int> olleet;
map<int, int> oikealt;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> f;
    oikealt[f]++;
    a[i] = f;
  }
  for (int i = 0; i < n; i++) {
    oikealt[a[i]]--;
    if (oikealt[a[i]] == 0) oikealt.erase(oikealt.find(a[i]));
    if (olleet.find(a[i]) == olleet.end()) ans += oikealt.size();
    olleet.insert(a[i]);
  }
  cout << ans;
}
