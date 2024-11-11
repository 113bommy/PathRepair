#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0;
  cin >> n;
  int x[n];
  for (int i = 0; i < n; i++) {
    cin >> x[n];
    if (x[i] == 1) a++;
  }
  if (a == 0)
    cout << "EASY";
  else
    cout << "HARD";
}
