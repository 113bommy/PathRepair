#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = n; i >= 1; i--) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s << '\n';
  return 0;
}
