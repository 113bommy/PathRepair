#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) cin >> s;
  if (n % 2)
    cout << "contest" << '\n';
  else
    cout << "home" << '\n';
}
