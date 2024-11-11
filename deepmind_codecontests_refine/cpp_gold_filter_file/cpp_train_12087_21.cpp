#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) k++;
  }
  if (k == n)
    cout << "EASY";
  else
    cout << "HARD";
}
