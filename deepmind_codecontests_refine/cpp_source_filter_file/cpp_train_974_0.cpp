#include <bits/stdc++.h>
using namespace std;
int main() {
  ;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  int i = 0;
  for (i = n; i > 0; i--)
    if (a[i] < a[i - 1]) break;
  cout << i;
}
