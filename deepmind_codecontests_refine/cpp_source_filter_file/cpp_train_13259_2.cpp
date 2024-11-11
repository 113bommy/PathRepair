#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < 4)
      ans ^= 0;
    else if (x < 16)
      ans ^= 1;
    else if (x < 82)
      ans ^= 2;
    else if (x < 6724)
      ans ^= 0;
    else if (x < 50626)
      ans ^= 3;
    else if (x < 2562991876LL)
      ans ^= 1;
    else
      ans ^= 2;
  }
  if (ans)
    cout << "Furlo" << endl;
  else
    cout << "Rubio";
}
