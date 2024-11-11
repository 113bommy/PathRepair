#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  bool re = false;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == 1) re = true;
  }
  if (re)
    cout << "HARD";
  else
    cout << "EASY";
  return 0;
}
