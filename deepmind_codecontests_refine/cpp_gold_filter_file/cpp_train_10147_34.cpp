#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  if (n & 1) {
    cout << "black\n";
  } else {
    cout << "white\n";
    cout << 1 << ' ' << 2 << '\n';
  }
  return 0;
}
