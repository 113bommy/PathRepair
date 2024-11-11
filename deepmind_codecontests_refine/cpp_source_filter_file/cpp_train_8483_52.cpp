#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int ma = min({a, b});
  int c = a - b;
  int ans = c / 2;
  cout << ma << " " << ans << endl;
}
