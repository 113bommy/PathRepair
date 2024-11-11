#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int a, p;
  cin >> a;
  while (a--) {
    cin >> p;
    if (p % 2) {
      cout << "First";
      return 0;
    }
  }
  cout << "Second";
  return 0;
}
