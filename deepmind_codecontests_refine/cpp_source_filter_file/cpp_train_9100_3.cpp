#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, n1, x, i, c = 0, sum = 0;
  vector<int> nn;
  cin >> n >> n1;
  while (n--) {
    cin >> x;
    nn.push_back(x);
  }
  sum = nn[0];
  for (i = 1; i < nn.size(); i++) {
    sum += nn[i];
  }
  while (sum > 0) {
    sum -= x;
    c++;
  }
  if (c == 0) {
    while (sum < 0) {
      sum += n1;
      c++;
    }
  }
  cout << c << endl;
}
