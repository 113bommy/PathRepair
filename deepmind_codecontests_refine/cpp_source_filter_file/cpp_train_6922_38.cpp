#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ld = long double;
using ulli = unsigned long long int;
void solve() {
  int na, nb, k, m;
  cin >> na >> nb >> k >> m;
  vector<int> nums_na(na), nums_nb(nb);
  for (auto& i : nums_na) {
    cin >> i;
  }
  for (auto& i : nums_nb) {
    cin >> i;
  }
  bool isLess = true;
  for (int i = na - k; i < na; i++) {
    for (int j = nb - m; j < nb; j++) {
      if (nums_na[i] < nums_nb[j]) {
        break;
      } else {
        isLess = !isLess;
        break;
      }
    }
    if (!isLess) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
