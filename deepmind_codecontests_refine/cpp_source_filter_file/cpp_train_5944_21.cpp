#include <bits/stdc++.h>
using namespace std;
int n, a[1021];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cout << (a[i] - (i % 2 == 0)) << " ";
  cout << endl;
}
