#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n / 2 + 1 << endl;
  for (int i = 1; i <= n / 2 + 1; i++) cout << 1 << " " << i << endl;
  for (int i = 2; i <= n - (n / 2 + 1) + 1; i++)
    cout << n / 2 + 1 << " " << i << endl;
}
