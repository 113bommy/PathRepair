#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s;
  cin >> n;
  cin >> s;
  for (int i = n; i > 0; i--) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s;
  return 0;
}
