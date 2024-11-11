#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c;
  cin >> a >> b >> c;
  if (a > min(b, c))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
