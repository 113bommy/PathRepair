#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, k = 1;
  cin >> n;
  int t[n];
  for (i = 0; i < n; i++) {
    cin >> t[i];
    if (t[i]) k = 0;
  }
  if (k)
    cout << "EASY";
  else
    cout << "HARD";
}
