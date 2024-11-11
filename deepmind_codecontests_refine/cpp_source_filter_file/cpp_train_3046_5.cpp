#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t = 0;
  cin >> t;
  for (int tttt = 0; tttt < t; tttt++) {
    int n, k, x = 0, y, i, j, ans = 0;
    string s;
    char ch;
    cin >> n >> k;
    std::map<int, int> mapp;
    for (i = 0; i < n; i++) {
      cin >> x;
      x = x % k;
      mapp[x]++;
    }
    int min = 0;
    for (auto it : mapp) {
      if (it.first != 0)
        if (it.second > min) min = it.second, ans = it.first;
    }
    cout << (ans == 0 ? ans : (min * k - ans + 1)) << "\n";
  }
}
