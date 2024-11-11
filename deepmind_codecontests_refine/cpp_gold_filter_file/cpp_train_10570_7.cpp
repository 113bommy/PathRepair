#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int side = 0;
  int sum = 0;
  while (n--) {
    int tmp;
    cin >> tmp;
    sum += tmp;
    side = max(side, tmp);
  }
  cout << side - (sum - side) + 1 << endl;
}
