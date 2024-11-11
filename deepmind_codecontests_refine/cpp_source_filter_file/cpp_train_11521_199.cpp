#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n <= 1) cout << "Ehab" << '\n';
  if (n % 2 == 0)
    cout << "Mahmoud" << '\n';
  else
    cout << "Ehab" << '\n';
  return 0;
}
