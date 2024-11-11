#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) cout << i << " ";
  cout << a + b + 1 << " ";
  for (int j = a + b; j > a; j--) cout << j << " ";
}
