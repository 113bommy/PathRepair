#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  if (a == 0 and b == 1)
    cout << "YES";
  else if (a == 1 and b == 0)
    cout << "NO";
  else if (a == 0 and b == 0)
    cout << "NO";
  else if (abs(a - b) <= 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
