#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  string s;
  int a, b, n, term = -1;
  cin >> a >> b >> n;
  for (int i = 0; i <= 9; i++) {
    int value = a * 10 + i;
    if (value % b == 0) {
      term = value;
      break;
    }
  }
  if (term == -1)
    cout << -1;
  else {
    s = to_string(term);
    for (int i = 1; i < n; i++) s = s + '0';
    cout << s;
  }
}
