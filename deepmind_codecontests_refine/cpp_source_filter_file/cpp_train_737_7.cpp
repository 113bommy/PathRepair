#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, mx = 0, answer = -1, f = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (f && x > mx)
      answer = i + 1, f = 0;
    else if (f)
      mx = max(mx, x + 1);
  }
  cout << answer;
}
