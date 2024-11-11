#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string l;
  cin >> n >> l;
  int ans = 0;
  l = '0' + l;
  l += '0';
  for (int i = 0; i < n; i++) {
    if (l[i] == '0' && l[i + 1] == '0' && l[i + 2] == '0') ans = 1;
    if (l[i] == '1' && l[i + 1] == '1') ans = 1;
  }
  if (n == 1 && l[0] == '0') ans = 1;
  if (ans)
    cout << "No";
  else
    cout << "Yes";
}
