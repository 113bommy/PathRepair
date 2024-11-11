#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, r;
  cin >> a >> b >> r;
  if (min(a, b) > 2 * r)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
  return 0;
}
