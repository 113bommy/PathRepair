#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, r;
  cin >> a >> b >> r;
  if (2 * r >= min(a, b)) {
    cout << "Second";
  } else {
    cout << "First";
  }
  return 0;
}
