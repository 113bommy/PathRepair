#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, i, n, c;
  cin >> n >> c;
  vector<int> v1;
  vector<int> v2;
  for (i = 0; i < n; i++) {
    cin >> x;
    v1.push_back(x);
  }
  for (i = 0; i < n; i++) {
    cin >> x;
    v2.push_back(x);
  }
  int q = v2[0], z = v2[n - 1], l, m, s = 0, t = 0;
  for (i = 0; i < n; i++) {
    if ((v1[i] - c * q) > 0) {
      l = v1[i] - c * q;
    } else {
      l = 0;
    }
    if ((v1[n - i - 1] - c * z) > 0) {
      m = v1[n - i - 1] - c * z;
    } else {
      m = 0;
    }
    s = l + s;
    t = t + m;
    q = q + v2[i + 1];
    z = z + v2[n - 2 - i];
  }
  if (s > t) {
    cout << "Limak";
  } else if (s < t) {
    cout << "Radewoosh";
  } else {
    cout << "Tie";
  }
}
