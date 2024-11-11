#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int prv = 1, ans = 0, MAX = 1;
  long long int a;
  while (n--) {
    cin >> a;
    if (prv <= a)
      ans++;
    else
      ans = 1;
    MAX = max(MAX, ans);
    prv = a;
  }
  cout << MAX;
  return 0;
}
