#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  string in;
  cin >> in;
  for (int i = 0; i < n - 1; i++) {
    if (in[i] == 'S' && in[i + 1] == 'F') ans++;
    if (in[i] == 'F' && in[i + 1] == 'S') ans--;
  }
  if (ans > 0)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
