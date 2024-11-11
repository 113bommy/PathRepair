#include <bits/stdc++.h>
using namespace std;
int main() {
  int xx[4] = {1, 0, -1, 0};
  int yy[4] = {0, 1, 0, -1};
  long long int a, b;
  cin >> a >> b;
  long long int x = 0;
  long long int y = 0;
  vector<long long int> v;
  for (long long int i = 1; i < 101; i++) {
    v.push_back(i);
    v.push_back(i);
  }
  if (a == 0 && b == 0) {
    cout << 0;
    return 0;
  }
  for (long long int i = 0; i < 100; i++) {
    long long int p = xx[i % 4];
    long long int q = yy[i % 4];
    for (long long int j = 0; j < v[i]; j++) {
      x += p;
      y += q;
      if (x == a && y == b) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
