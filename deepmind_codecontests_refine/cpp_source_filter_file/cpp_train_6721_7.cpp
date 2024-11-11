#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k = 0, t = 0;
  cin >> n;
  char ban[n + 1];
  for (i = 0; i < n; ++i) {
    cin >> ban[i];
  }
  for (i = 0; i < n; ++i) {
    if (ban[i] == '<')
      ++k;
    else
      break;
  }
  for (i = n; i > 0; --i) {
    if (ban[n] == '>')
      ++t;
    else
      break;
  }
  cout << t + k;
  return 0;
}
