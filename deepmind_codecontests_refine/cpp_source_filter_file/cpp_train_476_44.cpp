#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, v, u, t, f, p, q;
  cin >> n >> v >> u >> t >> f;
  q = n * v + t;
  p = n * u + f;
  if (q < p) {
    cout << "First" << endl;
  } else if (q > p) {
    cout << "Second" << endl;
  } else {
    cout << "Friendship" << endl;
  }
  return 0;
}
