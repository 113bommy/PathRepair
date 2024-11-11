#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int evn = 0, odd = 0;
  while (n--) {
    int x;
    cin >> x;
    if (x % 2)
      odd++;
    else
      evn++;
  }
  if (odd % 2)
    cout << odd;
  else
    cout << evn;
  return 0;
}
