#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n * n / 2 << endl;
  } else {
    cout << ((n * n) + 1) / 2 << endl;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) % 2 == 0) {
        cout << "C";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  return 0;
}
