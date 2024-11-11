#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string p;
  cin >> p;
  int n = p.length() - 1;
  int j = 0, dc = 0, tc;
  for (int i = n; i >= 0; i--) {
    if (p[j] == p[i]) tc++;
    j++;
  }
  for (int i = 0; i < n; i++) {
    if (p[i] != p[i + 1]) {
      dc = 1;
      break;
    }
  }
  if ((tc == n + 1) && (dc == 0))
    cout << "0";
  else if ((tc == n + 1) && (dc == 1))
    cout << n;
  else
    cout << n + 1;
  return 0;
}
