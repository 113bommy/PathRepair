#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int sum = 0;
  while (n--) {
    int x;
    cin >> x;
    sum += abs(x);
  }
  cout << sum << endl;
  return 0;
}
