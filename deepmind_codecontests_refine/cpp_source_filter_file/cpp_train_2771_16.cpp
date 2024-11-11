#include <bits/stdc++.h>
int x[2002], y[2002];
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> S;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    S.insert(x[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> y[i];
    S.insert(y[i]);
  }
  int val = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      if (S.find(x[i] ^ y[j]) != S.end()) val++;
    }
  }
  if (val & 1)
    cout << "Koyomi\n";
  else
    cout << "Karen\n";
  return 0;
}
