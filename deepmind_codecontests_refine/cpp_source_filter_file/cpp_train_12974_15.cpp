#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n, t;
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    t -= max(0, 86400 - x);
    if (n <= 0) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
