#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(3001, 0);
  while (n--) {
    int input;
    cin >> input;
    v[input] = 1;
  }
  for (int i = 1; i <= 3000; i++) {
    if (v[i] == 0) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
