#include <bits/stdc++.h>
int codd, i;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2) codd++;
  }
  if (codd == 0)
    cout << "First";
  else
    cout << "Second";
}
