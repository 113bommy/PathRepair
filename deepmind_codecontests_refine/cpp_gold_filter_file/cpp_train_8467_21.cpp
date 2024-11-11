#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, max = 0, ind = 0, cou = 0, j, sum = 0, k, min = 1000000;
  cin >> n;
  if (n < 0) {
    cout << "I'm too stupid to solve this problem";
    return 0;
  }
  if (n == 0) {
    cout << "0 0 0";
    return 0;
  }
  if (n == 1) {
    cout << "0 0 1";
    return 0;
  }
  if (n == 2) {
    cout << "0 1 1";
    return 0;
  }
  int x = 2;
  vector<int> v{1, 1};
  while (1) {
    v.push_back(v[x - 1] + v[x - 2]);
    if (n == v[x - 1] + v[x - 2]) break;
    x++;
  }
  cout << v[x - 2] << " " << v[x - 2] << " " << v[x - 3] << endl;
}
