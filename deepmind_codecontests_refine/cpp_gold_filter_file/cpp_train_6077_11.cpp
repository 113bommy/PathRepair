#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> v(100005);
vector<int> cache(1e5 + 10, -1);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  map<int, int> mp;
  for (long long i = 0; i < n; i++) {
    int x;
    cin >> x;
    set<int> st;
    for (int k = 2; k * k <= x; k++) {
      if (x % k == 0) {
        st.insert(k);
        while (x % k == 0) {
          x = x / k;
        }
      }
    }
    int mx = 0;
    if (x > 1) {
      st.insert(x);
    }
    for (auto it : st) {
      mp[it]++;
      mx = max(mx, mp[it]);
    }
    for (auto it : st) {
      mp[it] = mx;
    }
  }
  int maxi = 1;
  for (auto it : mp) maxi = max(maxi, it.second);
  cout << maxi << "\n";
}
